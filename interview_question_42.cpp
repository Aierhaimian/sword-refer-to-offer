#include <iostream>
#include <vector>

using namespace std;

// 找规律
// 动态规划
class Solution{
public:
    int maxSumOfSubArray(const vector<int> &arr)
    {
        if (arr.size() == 0)
            return 0;

        int curSum = 0;
        int maxSum = INT_MIN;

        for (int i=0; i<arr.size(); ++i)
        {
            if (curSum <= 0)
                curSum = arr[i];
            else
                curSum += arr[i];
            
            if (curSum > maxSum)
            {
                maxSum = curSum;
            }
        }

        return maxSum;
    }
};

int main()
{
    vector<int> vec = {1,-2,3,10,-4,7,2,-5};
    cout << Solution().maxSumOfSubArray(vec) << endl;
    return 0;
}

