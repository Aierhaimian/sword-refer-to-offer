#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution1 {
public:
    int numberOfOne(int num) {
        int cnt = 0;
        unsigned int flag = 1;
        while (flag) {
            if (num & flag)
                ++ cnt;
            flag = flag << 1;
        }
        return cnt;
    }
};

// 将num减1，再和原数按位相与
// 会把该整数最右边的1变成0
// 因此，一个整数的二进制表示中
// 有多少个1，就可以进行多少次这样的操作
// 每次都将最右边的1变为0
// 这样就可数出一个整数的二进制中有多少个1
class Solution2 {
public:
    int numberOfOne(int num) {
        int cnt = 0;

        while (num) {
            ++ cnt;
            num = (num -1) & num;
        }
        return cnt;
    }
};

int main()
{
    cout << Solution2().numberOfOne(0) << endl; // 0
    cout << Solution2().numberOfOne(1) << endl; // 1
    cout << Solution2().numberOfOne(10) << endl; // 2
    cout << Solution2().numberOfOne(0x7FFFFFFF) << endl; // 31
    cout << Solution2().numberOfOne(0xFFFFFFFF) << endl; // 32
    cout << Solution2().numberOfOne(0x80000000) << endl; // 1
    return 0;
}

