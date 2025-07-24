#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
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
