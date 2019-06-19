#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    bool findWords(vector<vector<char>>& board, string word) {
        m = board.size();
        assert(m > 0);
        n = board[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (searchWord(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    int dir[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}};
    int m, n;
    vector<vector<bool>> visited;
    bool inArea(int x, int y) {
        return x >=0 && x < m && y >=0 && y <n;
    }
    
    // 从board[startX][startY]开始，寻找word[index...word.size()]
    bool searchWord(const vector<vector<char>> &board, const string &word, size_t index, int startX, int startY) {
        if (index == word.size()-1)
            return board[startX][startY] == word[index];

        if (board[startX][startY] == word[index]) {
            visited[startX][startY] = true;
            // 从startX, startY出发，向四个方向寻找
            for (int i=0; i<4; ++i) {
                int newX = startX + dir[i][0];
                int newY = startY + dir[i][1];
                if (inArea(newX, newY) && !visited[newX][newY])
                    if (searchWord(board, word, index+1, newX, newY)) // 递归
                        return true;
            }
            visited[startX][startY] = false; // 本格没找到，回退到上一格
        }
        return false;
    }
};

int main()
{

    return 0;
}

