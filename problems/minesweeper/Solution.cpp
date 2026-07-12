#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // The approach is to use bfs to reveal squares around the clicked square.
    // Time complexity: O(mn)
    // Space complexity: O(mn)
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') board[click[0]][click[1]] = 'X';
        else if (board[click[0]][click[1]] == 'E') {
            // unordered_set<pair<int, int>>, before C++23, requires a custom hash function for insert.
            // For a bounded coordinates (say, 0 <= m, n <= 1000), we can use vector<vector<bool>> instead.
            vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
            queue<pair<int, int>> neighbors;
            neighbors.push({click[0], click[1]});
            while (neighbors.size()) {
                int mines{};
                vector<pair<int, int>> next;
                pair<int, int> curr = neighbors.front();
                neighbors.pop();
                for (int d = 0; d < 8; d++) {
                    int dr = curr.first + dirs[d][0], dc = curr.second + dirs[d][1];
                    if (dr < 0 || dr >= board.size() || dc < 0 || dc >= board[0].size() ||
                        seen[dr][dc]) continue;
                    if (board[dr][dc] == 'M') {
                        mines++;
                    }
                    else if (board[dr][dc] == 'E') {
                        next.emplace_back(make_pair(dr, dc));
                    }
                }
                if (mines > 0) {
                    board[curr.first][curr.second] = '0' + mines;
                }
                else {
                    board[curr.first][curr.second] = 'B';
                    for (auto neighbor : next) {
                        seen[neighbor.first][neighbor.second] = true;
                        neighbors.push(neighbor);
                    }
                }
            }
        }
        return board;
    }

    static void printBoard(vector<vector<char>> board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
private:
    int dirs[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    bool isInBound(int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n) return false;
        return true;
    }

    bool isInBound(const pair<int, int>& a, const pair<int, int>& b, int m, int n) {
        if (a.first + b.first < 0 || a.first + b.first >= m ||
            a.second + b.second < 0 || a.second + b.second >= n) return false;
        return true;
    }
};
