#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 回溯
class Solution{
public:
    vector<string> permutation(string &str)
    {
        res.clear();
        if(str.size() == 0)
            return res;
        generatePermutation(str, 0);
        return res;
    }
private:
    vector<string> res;
    void generatePermutation(string &str, int index)
    {
        if (index == str.size())
        {
            res.push_back(str);
        }
        else
        {
            for(int i=index; i<str.size(); ++i)
            {
                swap(str[index], str[i]);

                generatePermutation(str, index+1);

                swap(str[index], str[i]);
            }
        }
    }
};

int main()
{
    vector<string> res;
    string s = "abc";
    res = Solution().permutation(s);
    for (string str: res)
        cout << str << " ";
    cout << endl;
    return 0;
}

