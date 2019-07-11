#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution{
public:
    bool isPopOrder(vector<int> pPush, vector<int> pPop)
    {
        if (pPush.size() == 0 || pPop.size() == 0)
            return false;
        if (pPush.size() != pPop.size())
            return false;

        stack<int> stk;
        int i = 0, j = 0;
        while (i<pPop.size())
        {
            if (!stk.empty() && pPop[i] == stk.top())
            {
                i++;
                stk.pop();
                continue;
            }
            else {
                while(pPop[i] != pPush[j] && j < pPush.size())
                    stk.push(pPush[j++]);

                if(j == pPush.size() && i < pPop.size())
                    return false;
                else if (pPop[i] == pPush[j])
                {
                    i++;
                    j++;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {4,5,3,2,1};
    vector<int> arr3 = {4,3,5,1,2};
    vector<int> arr4 = {3,5,4,2,1};
    vector<int> arr5 = {3,5,4,1,2};
    cout << Solution().isPopOrder(arr1, arr2) << endl; // true
    cout << Solution().isPopOrder(arr1, arr3) << endl; // false
    cout << Solution().isPopOrder(arr1, arr4) << endl; // true
    cout << Solution().isPopOrder(arr1, arr5) << endl; // false
    vector<int> arr6 = {3};
    vector<int> arr7 = {5};
    cout << Solution().isPopOrder(arr6, arr7) << endl; // false
    vector<int> arr8 = {3};
    vector<int> arr9 = {3};
    cout << Solution().isPopOrder(arr8, arr9) << endl; // true
    return 0;
}

