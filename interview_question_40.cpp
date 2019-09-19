#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution{
    typedef multiset<int, greater<int>>           intSet;
    typedef multiset<int, greater<int>>::iterator setIter;
public:
    vector<int> getLeastNumber(const vector<int> &data, int k)
    {
        vector<int> res;
        leastNumber.clear();

        if (k < 1 || data.size()<k)
            return res;

        for(vector<int>::const_iterator iter=data.begin(); iter!=data.end(); ++iter)
        {
            if (leastNumber.size() < k)
                leastNumber.insert(*iter);
            else
            {
                setIter iterGreatest = leastNumber.begin();
                if (*iter < *(iterGreatest))
                {
                    leastNumber.erase(iterGreatest);
                    leastNumber.insert(*iter);
                }
            }
        }

        for(setIter iter=leastNumber.begin(); iter!=leastNumber.end(); ++iter)
            res.push_back(*iter);

        return res;
    }
private:
    intSet leastNumber;
};

int main()
{
    return 0;
}

