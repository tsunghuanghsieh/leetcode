#include <iomanip>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // The approach is to use bfs to determine all distances from any cell to all other cell in the grid.
    // It can start from a building, 1, to calculate distance to all empty space, 0, in the grid.
    // Alternatively, it can start from an empty space, 0, to calculate distances to all buildings, 1.
    // The approach here is the latter. The speculation was there may tend to have more 0s than 1s.
    int shortestDistance(vector<vector<int>>& grid) {
        int shortest = INT_MAX, row_size = grid.size(), col_size = grid[0].size();
        unordered_set<int> pos0s, pos1s;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   // up, right, down, left

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == 0) {
                    pos0s.insert(i * col_size + j);
                    continue;
                }
                if (grid[i][j] == 1) pos1s.insert(i * col_size + j);
                grid[i][j] = INT_MAX;
            }
        }
        if (pos0s.size() == 0) return -1;
        for (int pos : pos1s) {
            // do bfs from each building to determine distance from all empty space in the grid
            unordered_set<int> visited, seen1;
            queue<int> q;
            q.push(pos);
            seen1.insert(pos);
            int qsize = q.size(), step = 1;
            while (qsize > 0) {
                int val = q.front(), r = val / col_size, c = val % col_size;
                q.pop();
                qsize--;
                visited.insert(val);
                for (vector<int> dir : dirs) {
                    int dr = r + dir[0], dc = c + dir[1], adj = dr * col_size + dc;
                    if (pos1s.count(adj) > 0) seen1.insert(adj);
                    if (visited.count(adj) > 0 || dr < 0 || dr >= row_size || dc < 0 || dc >= col_size) continue;
                    if (grid[dr][dc] == INT_MAX) continue;
                    grid[dr][dc] += step;
                    q.push(adj);
                    visited.insert(adj);
                }
                if (qsize == 0) {
                    qsize = q.size();
                    step++;
                }
            }
            if (pos1s.size() != seen1.size()) return -1;   // some buildings are unreachable
            for (int pos : pos0s) {
                if (visited.count(pos) > 0) continue;
                grid[pos / col_size][pos % col_size] = INT_MAX;   // marking unreachable empty spaces
            }
        }
        for (int pos : pos0s) {
            shortest = min(shortest, grid[pos / col_size][pos % col_size]);
        }
        return (shortest != INT_MAX) ? shortest : -1;
    }
private:
    void printGrid(const vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == INT_MAX) cout << setw(3) << -1 << " ";
                else cout << setw(3) << grid[r][c] << " ";
            }
            cout << endl;
        }
    }
};
