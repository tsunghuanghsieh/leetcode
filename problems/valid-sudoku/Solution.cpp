#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln #1: vector<unordered_set<char>>, runtime and space O(n^2)
    // LC Editorial soln #2: vector<vector<int>, runtime and space O(n^2)
    // LC Editorial soln #1: vector<int> bitmasking, runtime O(n^2) and space O(n)
    //
    // This implementation matches LC Editorial soln #1.
    // LC Editorial soln #2 employs same logic using int, 1 to indicate existence.
    // LC Editorial soln #3 employs same logic using bit operator << to move, | to
    // store and & to determine existence.
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), blocks(9);
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                if (rows[r].count(board[r][c])) return false;
                if (cols[c].count(board[r][c])) return false;
                if (blocks[r / 3 * 3 + c / 3].count(board[r][c])) return false;
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                blocks[r / 3 * 3 + c / 3].insert(board[r][c]);
            }
        }
        printBoard(board);
        return true;
    }

private:
    void printBoard(vector<vector<char>>& board) {
        string separator = "----------------------";
        for (int r = 0; r < 9; r++) {
            if (r % 3 == 0) cout << separator << endl;
            for (int c = 0; c < 9; c++) {
                if (c % 3 == 0) cout << "|";
                cout << board[r][c] << " ";
                if (c + 1 == 9) cout << "|";
            }
            cout << endl;
        }
        cout << separator << endl;
    }
};
