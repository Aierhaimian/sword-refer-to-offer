#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Time  Complexity: O(m + n)
// Space Complexity: O(1)
class Solution {
public:
    bool findNum(const vector<vector<int>>& grid, int num) {
        int m = grid.size();
        if (m == 0) return false;
        int n = grid[0].size();

        int curX = 0, curY = n - 1;
        while (curX < m && curY >= 0) {
            if (grid[curX][curY] == num)
                return true;
            else if (grid[curX][curY] > num)
                -- curY;
            else if (grid[curX][curY] < num)
                ++ curX;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> grid = { {1, 2, 8, 9},
                                 {2, 4, 9, 12},
                                 {4, 7, 10, 13},
                                 {6, 8, 11, 15}};
    int num1 = 7, num2 = 5;
    cout << Solution().findNum(grid, num1) << endl;
    cout << Solution().findNum(grid, num2) << endl;
    return 0;
}

