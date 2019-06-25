#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution1 {
public:
    void printOneToMaxOfNDigits(int n) {
        if (n <= 0) return;

        num = vector<char>(n+1, '0');
        num[n] = '\0';

        while (!increment(n)) {
            printNumber(n);
        }
        cout << endl;
    }
private:
    vector<char> num;
    bool increment(int n) {
        bool isOverflow = false; // n位数是否溢出
        int nTakeOver = 0; // 进位标志
        for (int i=n-1; i>=0; i--) { // 从低位向高位加
            int nSum = num[i] - '0' + nTakeOver;
            if (i == n-1)
                nSum ++; // 每次加1

            if (nSum >= 10) {
                if (i == 0)
                    isOverflow = true; // 最高位溢出
                else {
                    nSum -= 10;
                    nTakeOver = 1; // 向高位产生进位
                    num[i] = '0' + nSum;
                }
            }
            else {
                num[i] = '0' + nSum;
                break;
            }
        }
        return isOverflow;
    }

    void printNumber(int n) {
        bool isBeginning0 = true; // 最高位前的0都不用打印出来，否则不符合十进制表示习惯

        for (int i=0; i<n; i++) {
            if (isBeginning0 && num[i] != '0')
                isBeginning0 = false;
            if (!isBeginning0) {
                cout << num[i];
            }
        }
        cout << "\t";
    }
};

class Solution2 {
public:
    void printOneToMaxOfNDigits(int n) {
        if (n <= 0) return ;

        num = vector<char>(n+1, '0');
        num[n] = '\0';

        for (int i=0; i<10; i++) {
            num[0] = i + '0';
            printOneToMaxOfNDigitsRecursively(n, 0);
        }
        cout << endl;
    }
private:
    vector<char> num;
    void printOneToMaxOfNDigitsRecursively(int n, int index) {
        if (index == n - 1) {
            printNumber(n);
            return;
        }

        for (int i=0; i<10; i++) {
            num[index+1] = i + '0';
            printOneToMaxOfNDigitsRecursively(n, index + 1);
        }
    }

    void printNumber(int n) {
        bool isBeginning0 = true; // 最高位前的0都不用打印出来，否则不符合十进制表示习惯

        for (int i=0; i<n; i++) {
            if (isBeginning0 && num[i] != '0')
                isBeginning0 = false;
            if (!isBeginning0) {
                cout << num[i];
            }
        }
        if (isBeginning0)
            return;
        cout << "\t";
    }
};

int main()
{
    Solution2().printOneToMaxOfNDigits(3);
    return 0;
}

