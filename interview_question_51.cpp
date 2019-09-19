#include <iostream>
#include <vector>

using namespace std;

// 数组中的逆序对
//
// 思路一：逐个元素向后看O(n^2)
// 思路二：根据归并排序，首先将数组一分为二
//         然后对数组merge，合并的过程中通过
//         对数组排序就可以得出数组的逆序对。
// 时间复杂度：O(nlog(n))
// 空间复杂度：O(n)
class Solution{
public:
    int inversePairs(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
            return 0;

        vector<int> cpy;
        for (int i: arr)
            cpy.push_back(i);

        int count = inversePairsCount(arr, cpy, 0, n-1);

        return count;
    }
private:
    int inversePairsCount(vector<int> &arr, vector<int> &cpy, int start, int end)
    {
        if (start == end)
        {
            cpy[start] = arr[start];
            return 0;
        }

        int len = (end - start)/2;

        int left = inversePairsCount(cpy, arr, start, start+len);
        int right = inversePairsCount(cpy, arr, start+len+1, end);

        // i初始化为前半段最后一个数字的下标
        int i = start + len;
        // j初始化为后半段最后一个数字的下标
        int j = end;
        int indexCpy = end;
        int count = 0;

        while(i >= start && j >= start+len+1)
        {
            if (arr[i] > arr[j])
            {
                cpy[indexCpy--] = arr[i--];
                count += j - start - len;
            }
            else
                cpy[indexCpy--] = arr[j--];
        }

        for (;i >= start; --i)
            cpy[indexCpy--] = arr[i];
        for (; j >= start+len+1; --j)
            cpy[indexCpy--] = arr[j];

        return left + right + count;
    }
};

int main()
{
    vector<int> arr = {9, 1, 4, 2, 6, 8, 3, 5, 7};
    cout << Solution().inversePairs(arr) << endl;
    return 0;
}

