#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Time  Complexity: O(logn)
// Space Complexity: O(1)
class Solution{
public:
    int numberOf1Between1AndN(int n)
    {
        if (n <= 0)
            return 0;
        string strN = to_string(n);
        return numberOf1(strN);
    }
private:
    int numberOf1(string &str)
    {
        if (str.size() == 0 || str[0] < '0' || str[0] >'9')
            return 0;

        int first = str[0] - '0';
        unsigned int len = static_cast<unsigned int>(str.size());

        if (len == 1 && first == 0)
            return 0;
        if (len == 1 && first > 0)
            return 1;

        int numFirstDigit = 0;
        if (first > 1)
            numFirstDigit = pow(10, (len - 1));
        else if (first == 1)
            numFirstDigit = atoi(str.c_str()+1) + 1;

        int numOtherDigit = first * (len - 1) * pow(10, (len - 2));

        string newStr = str.substr(1, len);
        int numRecurDigit = numberOf1(newStr);

        return numFirstDigit + numOtherDigit + numRecurDigit;
    }
};

int main()
{
    cout << Solution().numberOf1Between1AndN(1) << endl;
    cout << Solution().numberOf1Between1AndN(5) << endl;
    cout << Solution().numberOf1Between1AndN(10) << endl;
    cout << Solution().numberOf1Between1AndN(55) << endl;
    cout << Solution().numberOf1Between1AndN(99) << endl;
    cout << Solution().numberOf1Between1AndN(10000) << endl;
    cout << Solution().numberOf1Between1AndN(21345) << endl;
    cout << Solution().numberOf1Between1AndN(0) << endl;
    return 0;
}

