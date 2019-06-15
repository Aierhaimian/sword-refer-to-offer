#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <exception>

using namespace std;

// 遍历数组
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
public:
    int findMin(vector<int> numVec) {
        if (numVec.size() <= 1)
            throw "Invalid parameters";
        int cnt = -1;
        for (int i=0; i<numVec.size()-1; i++)
            if (numVec[i] > numVec[i+1]) {
                cnt = i + 1; 
                break;
            }
        if (cnt == -1)
            throw "No anwser found";
        return numVec[cnt];
    }
};

// 二分查找 + 双指针法
// Time  Complexity: O(logn)
// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int> numVec) {
        if (numVec.size() <= 1)
            throw "Invalid parameters";

        int i = 0, j = numVec.size()-1;
        // 当排序数组向后移动0个元素组成旋转数组时
        // 第一个元素即为最小元素，可直接返回
        int mid = i;// corner case
        while (numVec[i] >= numVec[j]) {
            if (j - i == 1) {
                mid = j;
                break;
            }

            mid = (i + j)/2;

            // corner case
            // 如果下标为i、j和mid指向三个相同的数字
            // 则只能顺序查找
            if (numVec[i] == numVec[j] &&
                numVec[mid] == numVec[i])
                return findInorder(numVec, i, j);

            if (numVec[i] <= numVec[mid])
                i = mid;
            else if (numVec[j] >= numVec[mid])
                j = mid;
        }
        return numVec[mid];
    }       
private:
    int findInorder(vector<int> &vec, int i, int j) {
        int res = vec[i];
        for (int k=i+1; k<=j; k++) {
            if (res > vec[k])
                res = vec[k];
        }
        return res;
    }
};

int main()
{
    vector<int> vec = {3, 4, 5, 1, 2};
    cout << Solution().findMin(vec) << endl;
    return 0;
}

