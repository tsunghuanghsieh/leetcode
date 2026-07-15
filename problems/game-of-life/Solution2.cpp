#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC Editorial: Follow-up: solve in place
    // To do that, we can temporarily set dead -> live from 0 to 2, and live -> dead from 1 to -1.
    // Run another pass on the board to update them.
    //
    // The second follow-up: the statement, in my opinion, was poorly worded. Per LC Editorial, its
    // focus is, how to address the scalability issue when the size of the board gets too big.
    // When the board is infinite, one way is to load a fraction of the board at a time. Since each
    // cell only requires 8 surrounding cells to determine its next state. We just need 3 rows of
    // cells at any given time.
    // Or when the live cells are sparely populated, we could save the location of the live cells
    // and apply the 4 rules on them.
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int neighbors = getNeighbors(r, c, board);
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 2;
                else if (board[r][c] == 1 && neighbors != 2 && neighbors != 3) board[r][c] = -1;
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 2) board[r][c] = 1;
                else if (board[r][c] == -1) board[r][c] = 0;
            }
        }
    }

private:
    int dirs[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    int getNeighbors(int r, int c, vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        int neighbors{};
        for (int d = 0; d < 8; d++) {
            int dr = r + dirs[d][0], dc = c + dirs[d][1];
            if (dr < 0 || dr >= rows || dc < 0 || dc >= cols) continue;
            if (abs(board[dr][dc]) == 1) neighbors++;
        }
        return neighbors;
    }
};