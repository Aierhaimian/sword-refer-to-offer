#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Brute Force
// Time  Complexity: O(n^2)
// Space Complexity: O(1)
class Solution1 {
public:
    vector<int> ReorderOddEven(vector<int> & arr) {
        int n = arr.size();
        if (n <= 1)
            return arr;

        int oddNum = 0;
        for (int i: arr)
            if (i%2)
                ++ oddNum;

        for (int i=0; i<n-1;) {
            if (i == oddNum)
                break;
            if (arr[i] % 2 == 0) {
                int tmp = arr[i];
                for (int j=i; j<n-1; j++)
                    arr[j] = arr[j+1];
                arr[n-1] = tmp;
            }
            else {
                ++ i;
            }
        }
        return arr;
    }
};

// Two Points -> 只完成基本功能，仅适合初级程序员
// Time  Complexity: O(logn)
// Space Complexity: O(1)
class Solution2 {
public:
    vector<int> ReorderOddEven(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1)
            return arr;

        int iBegin = 0, iEnd = n-1;
        while (iBegin < iEnd) {
            if (arr[iBegin]%2 == 0 && arr[iEnd]%2 != 0) { // 一偶一奇
                swap(arr[iBegin], arr[iEnd]);
                ++ iBegin;
                -- iEnd;
            }
            if (arr[iBegin]%2)
                ++ iBegin;
            if (arr[iEnd]%2 == 0)
                -- iEnd;
        }
        return arr;
    }
};

// 此次实现主要的优势在于可扩展性
// 并且调整了程序结构，使得性能更优
class Solution {
public:
    vector<int> ReorderOddEven(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1)
            return arr;

        int iBegin = 0, iEnd = n-1;
        while (iBegin < iEnd) {
            while (iBegin < iEnd && !isEven(arr[iBegin]))
                ++ iBegin;
            while (iBegin < iEnd && isEven(arr[iEnd]))
                -- iEnd;

            if (iBegin < iEnd)
                swap(arr[iBegin], arr[iEnd]);
        }
        return arr;
    }
private:
    bool isEven(int n) {
        return (n&1) == 0;
    }
};

void printVector(const vector<int> &vec) {
    for (int i: vec)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> vec1 = {1,2,3,4,5,6,7};
    vector<int> vec2 = {2,4,6,1,3,5,7};
    vector<int> vec3 = {1,3,5,7,2,4,6};
    vector<int> vec4 = {1,3,5,7};
    vector<int> vec5 = {2,4,6,8};
    vector<int> vec6 = {1,2,3,4,2,3,2};

    Solution().ReorderOddEven(vec1);
    Solution().ReorderOddEven(vec2);
    Solution().ReorderOddEven(vec3);
    Solution().ReorderOddEven(vec4);
    Solution().ReorderOddEven(vec5);
    Solution().ReorderOddEven(vec6);
    printVector(vec1);
    printVector(vec2);
    printVector(vec3);
    printVector(vec4);
    printVector(vec5);
    printVector(vec6);
    return 0;
}

