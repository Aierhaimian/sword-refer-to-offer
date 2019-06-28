#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示
// 其中A和C都是整数(可以有正负号，也可以没有)
// 而B是一个无符号整数
class Solution {
public:
    bool isNumeric(const string &sNum) {
        if (sNum.size() == 0)
            return false;

        int index = 0;
        // 扫描开头是否有数字
        bool numeric = scanInterger(sNum, index);

        // 如果出现'.'则接下来是数字的小数部分
        if (sNum[index] == '.') {
            ++index;

            // 下面一行代码用||的原因：
            //  1. 小数可以没有整数部分，如.123 <=> 0.123
            //  2. 小数点后面可以没有数字，如233. <=> 233.0
            //  3. 小数点前后都可以有数字，如233.666
            numeric = scanUnsignedInterger(sNum, index) || numeric;
        }

        // 如果出现'e'或者'E'，则接下来是数字的指数部分
        if (sNum[index] == 'e' || sNum[index] == 'E') {
            ++index;

            // 下面一行用&&的原因：
            //  1. 当e或E前面没有数字时，整个字符串不能表示数字
            //  2. 当e或E后面没有数字时，整个字符串不能表示数字
            numeric = scanInterger(sNum, index) && numeric;
        }

        return numeric && sNum[index] == '\0';
    }
private:
    bool scanUnsignedInterger(const string &sNum, int &index) {
        int before = index;
        while (sNum[index] != '\0' && sNum[index] >= '0' && sNum[index] <= '9')
            ++ index;
        // 当字符串中存在若干0~9的数字时，返回true
        return index > before;
    }

    bool scanInterger(const string &sNum, int &index) {
        if (sNum[index] == '+' || sNum[index] == '-')
            ++index;
        return scanUnsignedInterger(sNum, index);
    }
};

int main()
{
    cout << "Test 01: " << Solution().isNumeric("100") << " : 1" << endl;
    cout << "Test 02: " << Solution().isNumeric("123.45e+6") << " : 1" << endl;
    cout << "Test 03: " << Solution().isNumeric("+500") << " : 1" << endl;
    cout << "Test 04: " << Solution().isNumeric("5e2") << " : 1" << endl;
    cout << "Test 05: " << Solution().isNumeric("3.1416") << " : 1" << endl;
    cout << "Test 06: " << Solution().isNumeric("600.") << " : 1" << endl;
    cout << "Test 07: " << Solution().isNumeric("-.123") << " : 1" << endl;
    cout << "Test 08: " << Solution().isNumeric("-1E-16") << " : 1" << endl;
    cout << "Test 09: " << Solution().isNumeric("1.724348875849759375974893274E+308") << " : 1" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Test 10: " << Solution().isNumeric("12e") << " : 0" << endl;
    cout << "Test 11: " << Solution().isNumeric("1a3.14") << " : 0" << endl;
    cout << "Test 12: " << Solution().isNumeric("1+20") << " : 0" << endl;
    cout << "Test 13: " << Solution().isNumeric("1.2.3") << " : 0" << endl;
    cout << "Test 14: " << Solution().isNumeric("+-5") << " : 0" << endl;
    cout << "Test 15: " << Solution().isNumeric("12e5.4") << " : 0" << endl;
    cout << "Test 16: " << Solution().isNumeric(".") << " : 0" << endl;
    cout << "Test 17: " << Solution().isNumeric(".e1") << " : 0" << endl;
    cout << "Test 18: " << Solution().isNumeric("e1") << " : 0" << endl;
    cout << "Test 19: " << Solution().isNumeric("+.") << " : 0" << endl;
    cout << "Test 20: " << Solution().isNumeric("") << " : 0" << endl;
    return 0;
}

