#include <iomanip>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC soln #1: bfs
    // LC soln #2: A* algorithm
    //
    // This approach uses bfs with iterative approach and separate grid to maintain available k at each
    // cell and a queue for cells to visit next.
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size() - 1;   // 0-based index
        int n = grid[0].size() - 1;   // 0-based index
        if (k > m + n) return m + n;   // special case: shortest (manhattahn) distance
        vector<vector<int>> gridk(grid.size(), vector<int>(grid[0].size(), -1));   // available k at cell
        gridk[0][0] = k;
        queue<vector<int>> next;   // max queue
        next.push({0, 0});   // row, col
        int curr_size = next.size();
        int steps = 0;
        while (curr_size > 0) {
            auto [row, col] = tuple{next.front()[0], next.front()[1]};
            next.pop();
            if (row == m & col == n) return steps;
            for (int d = 0; d < 4; d++) {
                int nextRow = row + dirs[d][0], nextCol = col + dirs[d][1];
                if (0 > nextRow || m < nextRow || 0 > nextCol || n < nextCol) continue;   // bound check
                bool hasObs = grid[nextRow][nextCol];
                // skip seen and better (larger k) cell, exhausted k
                if (gridk[nextRow][nextCol] >= gridk[row][col] - hasObs) continue;
                gridk[nextRow][nextCol] = gridk[row][col] - hasObs;
                next.push({nextRow, nextCol});
            }
            if (--curr_size == 0) {
                curr_size = next.size();
                steps++;
            }
        }
        return -1;
    }
private:
    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};   // e, s, w, n
};
