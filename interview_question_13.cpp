#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if (threshold <0 || rows<=0 || cols <=0)
            return 0;
        
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        return countCore(threshold, rows, cols, 0, 0);
    }
private:
    int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> visited;

    bool inArea(const int &rows, const int &cols, int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    int getDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }

    int countCore(const int &threshold, const int &rows, const int &cols, int row, int col) {
        int cnt = 0;
        if (inArea(rows, cols, row, col) &&
            (getDigitSum(row) + getDigitSum(col) <= threshold) && !visited[row][col]) {
                visited[row][col] = true;
                cnt = 1 + countCore(threshold, rows, cols, row+d[0][0], col+d[0][1])
                        + countCore(threshold, rows, cols, row+d[1][0], col+d[1][1])
                        + countCore(threshold, rows, cols, row+d[2][0], col+d[2][1])
                        + countCore(threshold, rows, cols, row+d[3][0], col+d[3][1]);
        }

        return cnt;
    }
};

int main()
{
    cout << Solution().movingCount(5, 10, 10) << endl; // 21
    cout << Solution().movingCount(15, 20, 20) << endl; // 359
    cout << Solution().movingCount(10, 1, 100) << endl; // 29
    cout << Solution().movingCount(10, 1, 10) << endl; // 10
    cout << Solution().movingCount(15, 100, 1) << endl; // 79
    cout << Solution().movingCount(15, 10, 1) << endl; // 10
    cout << Solution().movingCount(15, 1, 1) << endl; // 1
    cout << Solution().movingCount(0, 1, 1) << endl; // 1
    cout << Solution().movingCount(-10, 10, 10) << endl; // 0

    return 0;
}

