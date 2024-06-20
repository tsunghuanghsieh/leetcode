#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), size = m * n;
        int r = 0, c = 0;
        vector<vector<int>> dirs({{-1, 1}, {0, 1}, {1, -1}, {1, 0}});   // ne, e, sw, s
        vector<int> res;
        for (int i = 0, dir = 0; i < size; i++) {
            res.emplace_back(mat[r][c]);
            if (r == 0 && c <= n - 1) {   // row 0
                if (dir == 0) {   // curr dir: ne
                    dir = (dir + 1) % 4;   // new dir: e
                    if (c == n - 1) r += dirs[dir][1];   // at max col, going s
                    else {
                        r += dirs[dir][0];
                        c += dirs[dir][1];
                    }
                }
                else if (dir == 1) {   // curr dir: e
                    if (mat.size() > 1) dir = (dir + 1) % 4;   // stay on e, unless more than 1 row
                    r += dirs[dir][0];
                    c += dirs[dir][1];
                }
            }
            else if (c == 0 && r <= m - 1) {   // col 0
                if (dir == 1) {   // curr dir: e
                    r += dirs[dir][1];
                }
                else if (dir == 2) {   // curr dir: sw
                    dir = (dir + 1) % 4;   // new dir: s
                    if (r == m - 1) c += dirs[dir][0];
                    else {
                        r += dirs[dir][0];
                        c += dirs[dir][1];
                    }
                } else if (dir == 3) {   // curr dir: s
                    dir = (dir + 1) % 4;   // new dir: ne
                    r += dirs[dir][0];
                    c += dirs[dir][1];
                }
            }
            else if (r == m - 1) {   // at max row other than col 0
                if (dir == 2) {   // curr dir: sw
                    dir = (dir + 1) % 4;
                    c += dirs[dir][0];
                }
                else {   // curr dir: s (e because at max row)
                    dir = (dir + 1) % 4;   // new dir: ne
                    r += dirs[dir][0];
                    c += dirs[dir][1];
                }
            }
            else if (c == n - 1) {   // at max col other than row 0
                if (dir == 0) {   // curr dir: ne
                    dir = (dir + 1) % 4;   // new dir: e
                    r += dirs[dir][1];
                }
                else {   // curr dir: e (s because at max col)
                    dir = (dir + 1) % 4;   // new dir: sw
                    r += dirs[dir][0];
                    c += dirs[dir][1];
                }
            }
            else {
                r += dirs[dir][0];
                c += dirs[dir][1];
            }
        }
        return res;
    }
};
