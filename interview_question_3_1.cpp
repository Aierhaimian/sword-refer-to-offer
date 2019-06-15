#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 长度为n的数组里所有的数字都在0到n-1的范围内
// 数组中某些数字是重复的
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool findDuplicate(vector<int>& arr, int& duplication) {
        if (arr.size() == 0)
            return false;

        for (int i=0; i<arr.size(); i++)
            if (arr[i] < 0 || arr[i] > arr.size() - 1)
                return false;

        for (int i=0; i<arr.size(); i++) {
            while (arr[i] != i) {
                if (arr[arr[i]] == arr[i]) {
                    duplication = arr[i];
                    return true;
                }
                else {
                    swap(arr[i], arr[arr[i]]);
                }
            }
        }
        return true;
    }
};

// 长度为n+1的数组中所有数字的范围在1到n之间
// 所以必然有一个数字是重复的
// 不修改数组，找出这个数字
// 采用二分查找法在1~n之间折半
// 如果1~m之间的数字总是大于n/2，则重复数字在1~m之间
// 缩小范围继续查找，反之亦然
// Time  Complexity: O(logn)
// Space Complexity: O(1)
class Solution2 {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int l = 1, r = n;
        while (l <= r) {
            int mid = l + ((r-l)>>1);
            int cnt = countRange(arr, l, mid);
            if (l == r) {
                if (cnt > 1)
                    return l;
                else
                    break;
            }

            if (cnt > (mid - l + 1))
                r = mid;
            else
                l = mid + 1;
        }
        return -1;
    }
private:
    int countRange(vector<int>& arr, int l, int r) {
        if (arr.size() == 0)
            return 0;

        int cnt = 0;
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] >= l && arr[i] <= r)
                cnt ++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> vec = {2, 3, 5, 1, 4, 3, 6, 7};
    cout << Solution2().findDuplicate(vec) << endl;
    return 0;
}

