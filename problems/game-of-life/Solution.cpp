#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> neighbors(rows, vector<int>(cols));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                neighbors[r][c] = countNeighbors(r, c, board);
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (ops[neighbors[r][c]]) {
                    board[r][c] |= values[neighbors[r][c]];
                }
                else {
                    board[r][c] &= values[neighbors[r][c]];
                }
            }
        }
    }

private:
    int dirs[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    // neighbors      0     1     2     3     4     5     6     7     8
    // op + value  && 0  && 0  || 0  || 1  && 0  && 0  && 0  && 0  && 0
    int ops[9] = {0, 0, 1, 1, 0, 0, 0, 0, 0};   // 0 is &&, 1 is ||
    int values[9] = {0, 0, 0, 1, 0, 0, 0, 0, 0};

    int countNeighbors(int r, int c, vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        int neighbors{};
        for (int d = 0; d < 8; d++) {
            int dr = r + dirs[d][0], dc = c + dirs[d][1];
            if (dr < 0 || dr >= rows || dc < 0 || dc >= cols) continue;
            if (board[dr][dc] == 1) neighbors++;
        }
        return neighbors;
    }
};
