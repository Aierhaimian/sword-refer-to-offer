#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> printMatrixClockwisely(vector<vector<int>> &arr) {
        vector<int> res;
        rows = arr.size();
        if(rows == 0) return res;
        columns = arr[0].size();

        int start = 0;
        while(rows > start*2 && columns > start*2) {
            printMatrixInCircle(arr, start, res);
            ++ start;
        }
        return res;
    }
private:
    int rows, columns;
    void printMatrixInCircle(const vector<vector<int>> &arr, int start, vector<int> &res) {
        int endX = rows - 1 - start;
        int endY = columns - 1 -start;

        // 从左向右打印一行
        for (int i=start; i<=endY; ++i)
            res.push_back(arr[start][i]);

        // 从上到下打印一列
        if (start < endX) {
            for (int i=start+1; i<=endX; ++i)
                res.push_back(arr[i][endY]);
        }

        // 从右到左打印一行
        if (start < endY && start < endX) {
            for (int i=endY-1; i>=start; --i)
                res.push_back(arr[endX][i]);
        }

        // 从下到上打印一列
        if (start < endY && start < endX - 1) {
            for (int i=endX-1; i>=start+1; --i)
                res.push_back(arr[i][start]);
        }
    }
};

int main()
{
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> res = Solution().printMatrixClockwisely(arr);
    for(int i: res)
        cout << i << " ";
    cout << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

