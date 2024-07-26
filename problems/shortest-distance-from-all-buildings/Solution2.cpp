#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC soln 1: bfs from 0
    // LC soln 2: bfs from 1
    // LC soln 3: bfs from 1 with optimizations
    //
    // Instead of tracking 0 (empty space) and 1 (building) separately using set<int> or unordered_set<int>
    // and storing distances from 1 (INT_MAX for 1, 2 and unreachable cell) in grid in Solution.cpp, this
    // implements LC soln 3, which uses a counter to identify unreachable cells and a separate matrix to
    // keep track of total distances after each building iteration.
    int shortestDistance(vector<vector<int>>& grid) {
        int shortest = INT_MAX;
        row_size = grid.size();
        col_size = grid[0].size();
        distances.resize(row_size, vector<int>(col_size));

        int step = 1, value = 0 /* counter to identify unreachable cells */;
        for (int r = 0; r < row_size; r++) {
            for (int c = 0; c < col_size; c++) {
                if (grid[r][c] == 1) {
                    shortest = bfs(r, c, value, grid);
                    if (shortest == INT_MAX) return -1;   // unreachable house w no adjacent empty space
                    value--;
                }
            }
        }
        return  shortest;
    }
private:
    int row_size, col_size;
    vector<vector<int>> distances;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   // up, right, down, left
    int bfs(int r1, int c1, int value, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({r1, c1});
        int qsize = q.size();
        int step = 1;
        // my initial approach was to increment a counter in the for loop below and a separate (r * c) loop
        // in shortestDistance to find mininum in the distances matrix. However this approach in LC soln 3
        // is more compact and doesn't seem to have any significant effect on the execution time in LC.
        int shortest = INT_MAX;
        while (qsize > 0) {
            auto [r, c] = q.front();
            q.pop();
            qsize--;
            for (auto dir : dirs) {
                int dr = r + dir[0], dc = c + dir[1];
                if (dr < 0 || dr >= row_size || dc < 0 || dc >= col_size || grid[dr][dc] != value) continue;
                grid[dr][dc] = value - 1;
                distances[dr][dc] += step;
                shortest = min(shortest, distances[dr][dc]);
                q.push({dr, dc});
            }
            if (qsize == 0) {
                qsize = q.size();
                step++;
            }
        }
        return shortest;
    }

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
