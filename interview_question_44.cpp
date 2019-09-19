#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int digitAtIndex(int index)
    {
        if (index < 0)
            return -1;

        int digits = 1;
        while (true)
        {
            int numbers = countOfIntegers(digits);
            if (index < numbers * digits) // 确定index是几位数
                return digitAtIndex(index, digits); // 在digits位数中确定index

            index -= digits * numbers;
            digits ++;
        }
        return -1;
    }
private:
    // 计算所有digits位数的个数
    int countOfIntegers(int digits)
    {
        if (digits == 1)
            return 10;
        int count = (int) pow(10, digits - 1);
        return 9 * count;
    }

    int digitAtIndex(int index, int digits)
    {
        int number = beginNumber(digits) + index/digits;
        int indexFromRight = digits - index%digits;
        for (int i=1; i < indexFromRight; ++i)
            number /= 10;
        return number%10;
    }

    // digits位数的第一个数是多少
    int beginNumber(int digits)
    {
        if (digits == 1)
            return 0;
        return (int)pow(10, digits-1);
    }
};

int main()
{
    cout << Solution().digitAtIndex(0) << endl;
    cout << Solution().digitAtIndex(1) << endl;
    cout << Solution().digitAtIndex(9) << endl;
    cout << Solution().digitAtIndex(10) << endl;
    cout << Solution().digitAtIndex(189) << endl;
    cout << Solution().digitAtIndex(190) << endl;
    cout << Solution().digitAtIndex(1000) << endl;
    cout << Solution().digitAtIndex(1001) << endl;
    cout << Solution().digitAtIndex(1002) << endl;
    return 0;
}

