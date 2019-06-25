#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Back-tracking
// Time  Complexity: O(2^n)
// Space Complexity: O(1)
class Solution1 {
public:
    int maxProductAfterCut(int len) {
        if (len <= 1) return 0;

        return generateRes(len);
    }
private:
    int generateRes(int len) {
        if (len == 1) return 1;

        int res = 1;
        for (int i=1; i<len; i++) {
            res = max(max(max(res, i*(len-i)), 
                          i*generateRes(len-i)), 
                      generateRes(i)*generateRes(len-i));
        }
        return res;
    }
};

// Memory Search
// Time  Complexity: O(n^2)
// Space Complexity: O(n)
class Solution2 {
public:
    int maxProductAfterCut(int len) {
        if (len <= 1) return 0;
        mem = vector<int>(len+1, 0);
        return generateRes(len);
    }
private:
    vector<int> mem;
    int generateRes(int len) {
        if (len == 1) return 1;

        if (mem[len]) return mem[len];
        
        int res = 1;
        for (int i=1; i<len; i++) {
            res = max(max(max(res, i*(len-i)), 
                          i*generateRes(len-i)), 
                      generateRes(i)*generateRes(len-i));
        }
        mem[len] = res;
        return res;

    }
};

// Dynamic Programming
// Time  Complexity: O(n^2)
// Space Complexity: O(n)

// f(n) = max(f(i)*f(n-i))  0<i<n
// 上式为从上到下的递归公式
// 由于递归有大量的重复子问题
// 故而可以从下往上计算
class Solution3 {
public:
    int maxProductAfterCut(int len) {
        if (len <= 1) return 0;
        if (len == 2) return 1;
        if (len == 3) return 2;

        vector<int> mem(len+1, 0);
        mem[0] = 0;
        mem[1] = 1;
        mem[2] = 2;
        mem[3] = 3;
        
        int max = 0;
        for (int i=4; i<=len; ++i) {
            max = 0;
            for (int j=1; j<=i/2; ++j) {
                int product = mem[j]*mem[i-j];
                if (max < product)
                    max = product;
            }
            mem[i] = max;
        }

        max = mem[len];
        return max;
    }
};

// Greedy algorithm
// Time  Complexity: O(1)
// Space Complexity: O(1)
class Solution4 {
public:
    int maxProductAfterCut(int len) {
        if (len <= 1) return 0;
        if (len == 2) return 1;
        if (len == 3) return 2;

        // 尽可能多地剪去长度为3的绳子段
        int timesOfThree = len / 3;
        // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段
        // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1
        if (len - timesOfThree*3 == 1)
            timesOfThree -= 1;

        int timesOfTwo = (len - timesOfThree*3) / 2;

        return static_cast<int>(pow(3, timesOfThree))*static_cast<int>(pow(2, timesOfTwo));
    }
};

int main()
{
    cout << Solution4().maxProductAfterCut(1) << endl; // 0
    cout << Solution4().maxProductAfterCut(2) << endl; // 1
    cout << Solution4().maxProductAfterCut(3) << endl; // 2
    cout << Solution4().maxProductAfterCut(4) << endl; // 4
    cout << Solution4().maxProductAfterCut(5) << endl; // 6
    cout << Solution4().maxProductAfterCut(6) << endl; // 9
    cout << Solution4().maxProductAfterCut(7) << endl; // 12
    cout << Solution4().maxProductAfterCut(8) << endl; // 18
    cout << Solution4().maxProductAfterCut(9) << endl; // 27
    cout << Solution4().maxProductAfterCut(10) << endl; // 36
    cout << Solution4().maxProductAfterCut(50) << endl; // 86093442
    return 0;
}

