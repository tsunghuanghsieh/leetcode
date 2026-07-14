#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // The approach is to use bfs to find the shortest path to the destination.
    //
    // This second attempt has a few differences from the first.
    // 1. use a separate grid to indicate visited instead of modify the input where setting 1 as visited.
    // 2. use pair<int, int> for coordinates instead of encoding/decoding row and col into an int.
    // 3. use a 2D array for the 8 directional paths, instead of 2 separate vector<int>.
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid[grid.size() - 1][grid.size() - 1] == 1) return -1;

        int grid_size = grid.size(), steps = 1;
        // prioritize diaganoal moves over along axis moves
        // se, sw, nw, ne, e, s, w, n
        int dirs[8][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(grid_size, vector<bool>(grid_size, false));
        queue<pair<int, int>> paths;
        visited[0][0] = true;
        paths.push({0, 0});
        int curr_size = paths.size();
        while (curr_size > 0) {
            pair<int, int> curr = paths.front();
            paths.pop();
            if (curr.first == grid_size - 1 && curr.second == grid_size - 1) return steps;
            for (int d = 0; d < 8; d++) {
                int dr = curr.first + dirs[d][0], dc = curr.second + dirs[d][1];
                if (dr < 0 || dr >= grid_size || dc < 0 || dc >= grid_size || grid[dr][dc] == 1 ||
                    visited[dr][dc]) continue;
                paths.push({dr, dc});
                visited[dr][dc] = true;
            }
            if (--curr_size == 0) {
                curr_size = paths.size();
                steps++;
            }
        }
        return -1;
    }
};
