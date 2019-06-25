#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    double power(double base, int exponent) {
        double res;
        try {
            if (equalDouble(base, 0.0) && exponent < 0) {
                throw "Division by zero condition!";
            }

            unsigned int absExponent = static_cast<unsigned int>(exponent);
            if (exponent < 0)
                absExponent = static_cast<unsigned int>(abs(exponent));

            res = powerWithUnsignedExponent(base, absExponent);
            if (exponent < 0)
                res = 1.0 / res;
        }catch (const char *msg) {
            cerr << msg << endl;
            res = 0;
        }
        return res;
    }
private:
    bool equalDouble(double num1, double num2) {
        return (num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001);
    }

    // a^n = a^(n/2)*a^(n/2) n为偶数
    // a^n = a^((n-1)/2)*a^((n-1)/2) n为奇数
    double powerWithUnsignedExponent(double base, unsigned int exponent) {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;

        double res = powerWithUnsignedExponent(base, exponent >> 1);
        res *= res;
        if ((exponent & 0x1) == 1)
            res *= base;
        return res;
    }
};

int main()
{
    cout << Solution().power(2, 3) << endl; // 8
    cout << Solution().power(-2, 3) << endl; // -8
    cout << Solution().power(2, -3) << endl; // 0.125
    cout << Solution().power(2, 0) << endl; // 1
    cout << Solution().power(0, 0) << endl; // 0, 1
    cout << Solution().power(0, 4) << endl; // 0
    cout << Solution().power(2, 32) << endl;
    cout << Solution().power(0.0, -4) << endl; // 异常
    return 0;
}

