#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    string replaceSpace(string S) {
        if (S.size() == 0)
            return S;

        int spaceNum = 0;
        for (char c: S) {
            if (c == ' ')
                ++ spaceNum;
        }

        int p1 = S.size() - 1;
        int appendNum = 2*spaceNum;
        while (appendNum) {
            S.append(" ");
            -- appendNum;
        }

        int p2 = S.size() - 1;
        while (p1 >= 0 && p1 < p2) {
            if (S[p1] == ' ') {
                S[p2--] = '0';
                S[p2--] = '2';
                S[p2--] = '%';
            }
            else {
                S[p2--] = S[p1];
            }
            -- p1;
        }
        return S;
    }
};

class Test
{
public:
    void do_test(const string& testName, string& s, const string& expected) {
        if (testName != "")
            cout << testName << " begins: ";

        string testRes = Solution().replaceSpace(s);

        if (testRes == expected)
            cout << "passed." << endl;
        else
            cout << "failed." << endl;
    }
};

int main()
{
    string str1 = "hello world";
    string str2 = " helloworld";
    string str3 = "helloworld ";
    string str4 = "hello  world";
    string str5 = "";
    string str6 = " ";
    string str7 = "helloworld";
    string str8 = "    ";

    Test test;
    test.do_test("Test1", str1, "hello%20world");
    test.do_test("Test2", str2, "%20helloworld");
    test.do_test("Test3", str3, "helloworld%20");
    test.do_test("Test4", str4, "hello%20%20world");
    test.do_test("Test5", str5, "");
    test.do_test("Test6", str6, "%20");
    test.do_test("Test7", str7, "helloworld");
    test.do_test("Test8", str8, "%20%20%20%20");
    return 0;
}

