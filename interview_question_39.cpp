#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int MoreThanHalfNum(const vector<int> num)
    {
        if (num.size() == 0)
            return 0;

        int res = num[0];
        int times = 1;
        for(int i=1; i<num.size(); ++i)
        {
            if (times == 0)
            {
                res = num[i];
                times = 1;
            }
            else if (res == num[i])
                times += 1;
            else
                times -= 1;
        }

        if (!checkMoreThanHalf(num, res))
            res = 0;

        return res;
    }
private:
    bool checkMoreThanHalf(const vector<int> &num, int &res)
    {
        bool flag = true;
        int cnt = 0;
        for (int i=0; i<num.size(); ++i)
        {
            if (res == num[i])
                ++ cnt;
        }

        if (cnt*2 <= num.size())
            flag = false;

        return flag;
    }
};

int main()
{
    vector<int> num = {1,2,3,2,2,2,2,4,5};
    cout << Solution().MoreThanHalfNum(num) << endl;
    return 0;
}

