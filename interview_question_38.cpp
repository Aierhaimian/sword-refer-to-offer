#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 回溯
// 如果不排除重复选择，则
// 不支持字符串中有重复字符的全排列
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
                if (needSwap(str, index, i))
                {
                    swap(str[index], str[i]);

                    generatePermutation(str, index+1); // 对剩余元素进行递归求解

                    swap(str[index], str[i]);
                }
            }
        }
    }

    bool needSwap(string &str, int begin, int end)
    {
        for (int i=begin; i<end; ++i)
            if (str[i] == str[end])
                return false;
        return true;
    }
};

int main()
{
    vector<string> res;
    string s = "abbc";
    res = Solution().permutation(s);
    for (string str: res)
        cout << str << " ";
    cout << endl;
    return 0;
}

