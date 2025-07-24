#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    // LC Editorial soln #2
    // Istead of using separate variables to keep track of player's moves, it uses +1/-1 for
    // player 1 and 2 respectively, and at any time row/col/diagonal fwd/bwd is at +n/-n, the
    // player is the winner.
    //
    // My initial approach uses rows and cols to keep track of players moves, using bitmask
    // 1 for player 1, 2 for player 2 and 3 for both players; rows_count and cols_count for
    // count of player's move on each row and col. Similar df, db, df_count, df_count for
    // forward diagonal nad backward diagonal.
    //
    // Runtime complexity: O(1)
    // Space complexity: O(n)
    TicTacToe(int n) : _n(n) {
        rows.resize(n);
        cols.resize(n);
    }

    int move(int row, int col, int player) {
        rows[row] += pscore[player];
        cols[col] += pscore[player];
        if (row == col) df += pscore[player];
        if (row + col + 1 == _n) db += pscore[player];

        if (abs(rows[row]) == _n || abs(cols[col]) == _n || abs(df) == _n || abs(db) == _n) return player;
        return 0;
    }
private:
    int _n, df = 0, db = 0;
    vector<int> rows, cols;
    const vector<int> pscore = {0, 1, -1};
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
