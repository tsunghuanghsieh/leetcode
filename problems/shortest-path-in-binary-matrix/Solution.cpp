#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;

        int row = 0, col = 0, n = grid.size();
        queue<int> q;   // encoding [r, c] by r * n + c
        q.push(0);
        grid[0][0] = 1;
        int size = q.size(), count = 1;
        while (q.size()) {
            int idx = q.front(), row = idx / n, col = idx % n;
            q.pop();
            size--;
            if (row == n - 1 && col == n - 1) return count;
            // breadth first traversal
            for (int i = 0; i < dr.size(); i++) {
                int r = row + dr[i], c = col + dc[i];
                if (r < 0 || c < 0 || r == n || c == n || grid[r][c] == 1) continue;
                q.push(r * n + c);
                // modify grid in place, instead of using set, to keep track of those that have been in the queue
                grid[r][c] = 1;
            }
            if (size == 0) {
                size = q.size();
                if (size == 0) return -1;
                count++;
            }
        }
        return count;
    }
private:
    // combining direction row and direction column
    // the movements are dr [1, 1], r [0, 1], d [1, 0], dl [1, -1], ul [-1, -1], ur [-1, 1], l [0, -1] and u [-1, 0].
    const vector<int> dr = {1, 0, 1, 1, -1, -1, 0, -1};
    const vector<int> dc = {1, 1, 0, -1, -1, 1, -1, 0};
};
