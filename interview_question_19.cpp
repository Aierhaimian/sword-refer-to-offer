#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// DFS Recursively
// Time  Complexity: O((s+p)*2^(s+p))
// Space Complexity: O(s+p)
class Solution1 {
public:
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }
private:
    bool match(const string &s, int sl, const string &p, int pl) {
        // str已经匹配完了，pattern还有剩余元素
        if (sl == s.size()) return no_more_match(p, pl);
        // str未匹配完，pattern已经匹配完了
        if (pl == p.size()) return false;

        // str与pattern都未匹配完，分为三种情况
        //  1. pattern的pl+1位为'*'
        //      a. str[sl] == pattern[pl]或者pattern的pl位为'.'
        //          i. '*'前面的字符出现任意次
        //          ii. ‘*’前面的字符出现0次
        //      b. str[sl] != pattern[pl]并且pattern的pl位不是'.': '*'前面的字符出现0次
        //  2. pattern的pl+1位不是'*'：pattern的pl位为'.'或者str[sl] == pattern[pl]: 直接匹配下一个字符
        //  3. pattern的pl+1位不是'*'：pattern的pl位不是'.'并且str[sl] != pattern[pl]：返回false
        if (pl+1<p.size() && p[pl+1] == '*') {
            if (s[sl] == p[pl] || p[pl] == '.')
                return match(s, sl+1, p, pl) || match(s, sl, p, pl+2);
            else
                return match(s, sl, p, pl+2);
        }
        // str与pattern字符匹配
        else if (s[sl] == p[pl] || p[pl] == '.')
            return match(s, sl+1, p, pl+1);

        // 其余情况都不匹配
        return false;
    }

    bool no_more_match(const string &p, int pl) {
        int i;
        for (i = pl; i<p.size(); i+=2)
            if (i+1<p.size() && p[i+1] != '*') return false;
        return i == p.size();
    }
};


// Memory Search
// Time  Complexity: O(s*p)
// Space Complexity: O(s*p)
class Solution2 {
public:
    bool isMatch(string s, string p) {
        mem = vector<vector<int>>(s.size(), vector<int>(p.size(), -1));
        return match(s, 0, p, 0);
    }
private:
    vector<vector<int>> mem;
    bool match(const string &s, int sl, const string &p, int pl) {
        // str已经匹配完了，pattern还有剩余元素
        if (sl == s.size()) return no_more_match(p, pl);
        // str未匹配完，pattern已经匹配完了
        if (pl == p.size()) return false;

        if (mem[sl][pl] != -1)
            return mem[sl][pl];

        // str与pattern都未匹配完，分为三种情况
        //  1. pattern的pl+1位为'*'
        //      a. str[sl] == pattern[pl]或者pattern的pl位为'.'
        //          i. '*'前面的字符出现任意次
        //          ii. ‘*’前面的字符出现0次
        //      b. str[sl] != pattern[pl]并且pattern的pl位不是'.': '*'前面的字符出现0次
        //  2. pattern的pl+1位不是'*'：pattern的pl位为'.'或者str[sl] == pattern[pl]: 直接匹配下一个字符
        //  3. pattern的pl+1位不是'*'：pattern的pl位不是'.'并且str[sl] != pattern[pl]：返回false
        if (pl+1<p.size() && p[pl+1] == '*') {
            if (s[sl] == p[pl] || p[pl] == '.')
                return mem[sl][pl] = match(s, sl+1, p, pl) || match(s, sl, p, pl+2);
            else
                return mem[sl][pl] = match(s, sl, p, pl+2);
        }
        // str与pattern字符匹配
        else if (s[sl] == p[pl] || p[pl] == '.')
            return mem[sl][pl] = match(s, sl+1, p, pl+1);

        // 其余情况都不匹配
        return mem[sl][pl] = false;
    }

    bool no_more_match(const string &p, int pl) {
        int i;
        for (i = pl; i<p.size(); i+=2)
            if (i+1<p.size() && p[i+1] != '*') return false;
        return i == p.size();
    }
};

// Dynamic Programming
// Time  Complexity: O(s*p)
// Space Complexity: O(s*p)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // dp[i][j] represents if the 1st i characters in s can match the 1st j characters in p
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // initialization:
        // 1. dp[0][0] = true, since empty string matches empty pattern
        dp[0][0] = true;

        // 2. dp[i][0] = false(which is default value of the boolean array)
        // since empty pattern cannot match non-empty string
        // 3. dp[0][j]: what pattern matches empty string ""?
        // It should be "#*#*#*#*...", or "(#*)*" if allow me to represent regex using regex :P,
        // and for this case we need to check manually

        // for dp[0][j], as we can see, the length of pattern should be even,
        // the char at the even position should be *,
        // thus for odd length, dp[0][j] = false which is default. So we can
        // just skip the odd position, i.e. j starts from 2, the interval of j is also 2.
        // and notice that the length of repeat sub-pattern #* is only 2, we
        // can just make use of dp[0][j - 2] rather than scanning j length each time
        // for checking if it matches #*#*#*#*.
        for (int j=2; j<n+1; j+=2) {
            if (p[j-1] == '*' && dp[0][j-2])
                dp[0][j] = true;
        }

        // the induction rule is very similar to edit distance, where we also consider from the end.
        // induction rule:
        // 1. if p[j] == s[i], dp[i][j] = dp[i - 1][j - 1]
        //    ######a(i)
        //    ####a(j)
        // 2. if p[j] == '.', dp[i][j] = dp[i - 1][j - 1]
        //    #######a(i)
        //    ####.(j)
        // 3. if p[j] == '*':
        //    1. if p[j-1] != '.' && p[j-1] != s[i] then b* is counted as empty. dp[i][j] = dp[i][j - 2]
        //       #####a(i)
        //       ####b*(j)
        //    2.if p[j-1] == '.' || p[j-1] == s[i]:
        //       ######a(i)
        //       ####.*(j)
        //
        //       #####a(i)
        //       ###a*(j)
        //      2.1 if p[j-1] is counted as empty, then dp[i][j] = dp[i][j - 2]
        //      2.2 if counted as one, then dp[i][j] = dp[i - 1][j - 2]
        //      2.3 if counted as multiple, then dp[i][j] = dp[i - 1][j]

        // recap:
        // dp[i][j] = dp[i - 1][j - 1]
        // dp[i][j] = dp[i - 1][j - 1]
        // dp[i][j] = dp[i][j - 2]
        // dp[i][j] = dp[i][j - 2]
        // dp[i][j] = dp[i - 1][j - 2]
        // dp[i][j] = dp[i - 1][j]
        // Observation: from above, we can see to get dp[i][j],
        // we need to know previous elements in dp, i.e. we need to compute them first.
        // which determines i goes from 1 to m - 1, j goes from 1 to n + 1

        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                char curS = s[i-1];
                char curP = p[j-1];
                if (curP == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }else if (curP == '*') {
                    char preCurP = p[j-2];
                    if (preCurP != '.' && preCurP != curS) {
                        dp[i][j] = dp[i][j-2];
                    }else {
                        dp[i][j] = (dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j]);
                    }
                }else if (curS == curP) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    cout << "Test01: " << Solution().isMatch("", "") << " : true" << endl;
    cout << "Test02: " << Solution().isMatch("", ".*") << " : true" << endl;
    cout << "Test03: " << Solution().isMatch("", ".") << " : false" << endl;
    cout << "Test04: " << Solution().isMatch("", "c*") << " : true" << endl;
    cout << "Test05: " << Solution().isMatch("a", ".*") << " : true" << endl;
    cout << "Test06: " << Solution().isMatch("a", "a.") << " : false" << endl;
    cout << "Test07: " << Solution().isMatch("a", "") << " : false" << endl;
    cout << "Test08: " << Solution().isMatch("a", ".") << " : true" << endl;
    cout << "Test09: " << Solution().isMatch("a", "ab*") << " : true" << endl;
    cout << "Test10: " << Solution().isMatch("a", "ab*a") << " : false" << endl;
    cout << "Test11: " << Solution().isMatch("aa", "aa") << " : true" << endl;
    cout << "Test12: " << Solution().isMatch("aa", "a*") << " : true" << endl;
    cout << "Test13: " << Solution().isMatch("aa", ".*") << " : true" << endl;
    cout << "Test14: " << Solution().isMatch("aa", ".") << " : false" << endl;
    cout << "Test15: " << Solution().isMatch("ab", ".*") << " : true" << endl;
    cout << "Test16: " << Solution().isMatch("ab", "..") << " : true" << endl;
    cout << "Test17: " << Solution().isMatch("aaa", "aa*") << " : true" << endl;
    cout << "Test18: " << Solution().isMatch("aaa", "aa.a") << " : false" << endl;
    cout << "Test19: " << Solution().isMatch("aaa", "a.a") << " : true" << endl;
    cout << "Test20: " << Solution().isMatch("aaa", ".a") << " : false" << endl;
    cout << "Test21: " << Solution().isMatch("aaa", "a*a") << " : true" << endl;
    cout << "Test22: " << Solution().isMatch("aaa", "ab*a") << " : false" << endl;
    cout << "Test23: " << Solution().isMatch("aaa", "ab*ac*a") << " : true" << endl;
    cout << "Test24: " << Solution().isMatch("aaa", "ab*a*c*a") << " : true" << endl;
    cout << "Test25: " << Solution().isMatch("aaa", ".*") << " : true" << endl;
    cout << "Test26: " << Solution().isMatch("aab", "c*a*b") << " : true" << endl;
    cout << "Test27: " << Solution().isMatch("aaca", "ab*a*c*a") << " : true" << endl;
    cout << "Test28: " << Solution().isMatch("aaba", "ab*a*c*a") << " : false" << endl;
    cout << "Test29: " << Solution().isMatch("bbbba", ".*a*a") << " : true" << endl;
    cout << "Test30: " << Solution().isMatch("bcbbabab", ".*a*a") << " : false" << endl;
    return 0;
}

