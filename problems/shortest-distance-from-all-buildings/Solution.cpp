#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    // The approach is to use bfs to determine all distances from any cell to all other cell in the grid.
    // It can start from a building, 1, to calculate distance to all empty space, 0, in the grid.
    // Alternatively, it can start from an empty space, 0, to calculate distances to all buildings, 1.
    // The approach here is the latter. The speculation was there may tend to have more 0s than 1s.
    //
    // The implementation using unordered_set<int>, coverting 2D indices into 1D (row * col_size + col),
    // incurs too much translation costs during execution on big test cases individually, yet it passes
    // all LC tests at ~2500ms.
    //
    // NOTE: unordered_set does not have built-in hash function for vector<int> and pair<int, int>.
    //
    // The implementation using set<pair<int, int>> runs noticeably faster on big test cases individually,
    // however it fails at LC test case 84 (test8.txt) with TLE. Running test case 84 individually passes.
    int shortestDistance(vector<vector<int>>& grid) {
        int shortest = INT_MAX, row_size = grid.size(), col_size = grid[0].size();
        set<pair<int, int>> pos0s, pos1s;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   // up, right, down, left

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == 0) {
                    pos0s.insert({i, j});
                    continue;
                }
                if (grid[i][j] == 1) pos1s.insert({i, j});
                grid[i][j] = INT_MAX;
            }
        }
        if (pos0s.size() == 0) return -1;
        for (auto [r1, c1] : pos1s) {
            // do bfs from each building to determine distance from all empty space in the grid
            set<pair<int, int>> visited, seen1;
            queue<pair<int, int>> q;
            q.push({r1, c1});
            seen1.insert({r1, c1});
            int qsize = q.size(), step = 1;
            while (qsize > 0) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                qsize--;
                visited.insert({r, c});
                for (vector<int> dir : dirs) {
                    int dr = r + dir[0], dc = c + dir[1];
                    if (pos1s.count({dr, dc}) > 0) seen1.insert({dr, dc});
                    if (visited.count({dr, dc}) > 0 || dr < 0 || dr >= row_size || dc < 0 || dc >= col_size) continue;
                    if (grid[dr][dc] == INT_MAX) continue;
                    grid[dr][dc] += step;
                    q.push({dr, dc});
                    visited.insert({dr, dc});
                }
                if (qsize == 0) {
                    qsize = q.size();
                    step++;
                }
            }
            if (pos1s.size() != seen1.size()) return -1;   // some buildings are unreachable
            for (auto [r0, c0] : pos0s) {
                if (visited.count({r0, c0}) > 0) continue;
                grid[r0][c0] = INT_MAX;   // marking unreachable empty spaces
            }
        }
        for (auto [r0, c0] : pos0s) {
            shortest = min(shortest, grid[r0][c0]);
        }
        return (shortest != INT_MAX) ? shortest : -1;
    }
private:
    void printGrid(const vector<vector<int>>& grid) {
        int maxDist = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == INT_MAX) continue;
                maxDist = max(maxDist, grid[r][c]);
            }
        }
        int digits = 1;
        while (maxDist /= 10) digits++;
        if (digits == 1) digits++;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == INT_MAX) cout << setw(digits) << -1 << " ";
                else cout << setw(digits) << grid[r][c] << " ";
            }
            cout << endl;
        }
    }
};
