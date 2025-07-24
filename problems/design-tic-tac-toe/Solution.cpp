#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    // My initial approach uses rows and cols to keep track of players choices, using bitmask
    // 1, 2 and 3 for both players; rows_count and cols_count for count of player's move on
    // each row and col. Similar df, db, df_count, df_count for forward diagonal nad backward
    // diagonal.
    //
    // Runtime complexity: O(1)
    // Space complexity: O(n)
    TicTacToe(int n) : _n(n), df_count(3), db_count(3) {
        rows.resize(n);
        cols.resize(n);
        rows_count.resize(3, vector<int>(n));
        cols_count.resize(3, vector<int>(n));
    }

    int move(int row, int col, int player) {
        rows[row] |= player;
        rows_count[player][row]++;
        cols[col] |= player;
        cols_count[player][col]++;
        if (row == col) {
            df |= player;
            df_count[player]++;
        }
        if (row + col + 1 == _n) {
            db |= player;
            db_count[player]++;
        }
        if (rows_count[player][row] == _n || cols_count[player][col] == _n ||
            (df == player && df_count[player] == _n) || (db == player && db_count[player] == _n)) return player;
        return 0;
    }
private:
    int _n, df = 0, db = 0;
    vector<int> rows, cols, df_count, db_count;
    vector<vector<int>> rows_count, cols_count;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
