#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution1 {
public:
    // LC Editorial soln 1: expand grid by 3x
    // we can just count the number of cluster 0s.
    //  /\    0  0  1  1  0  0
    //  \/    0  1  0  0  1  0
    //        1  0  0  0  0  1
    //        0  1  0  0  1  0
    //        0  0  1  1  0  0
    int regionsBySlashes(vector<string>& grid) {
        int regions = 0, n = grid.size(), nx3 = n * 3;

        int **grid3x = new int *[nx3];
        // expand grid by 3x
        for (int i = 0; i < nx3; i++) grid3x[i] = new int[nx3]();   // () to initialize to 0
        // use 1s to represent forward and backward slash and 0 for whitespace.
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '/') {
                    grid3x[3 * r][3 * c + 2] = grid3x[3 * r + 1][3 * c + 1] = grid3x[3 * r + 2][3 * c] = 1;
                }
                else if (grid[r][c] == '\\') {
                    grid3x[3 * r][3 * c] = grid3x[3 * r + 1][3 * c + 1] = grid3x[3 * r + 2][3 * c + 2] = 1;
                }
            }
        }
        // use bfs to counter clusters of 0s.
        for (int r = 0; r < nx3; r++) {
            for (int c = 0; c < nx3; c++) {
                if (grid3x[r][c] != 0) continue;
                bfs(grid3x, nx3, r, c);
                regions++;
            }
        }
        return regions;
    }
private:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void bfs(int **grid3x, int grid_size, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int adj_r = p.first + dirs[d][0], adj_c = p.second + dirs[d][1];
                if (adj_r < 0 || adj_r >= grid_size || adj_c < 0 || adj_c >= grid_size ||
                    grid3x[adj_r][adj_c] != 0 || grid3x[p.first][p.second] != 0) continue;
                q.push({adj_r, adj_c});
            }
            grid3x[p.first][p.second] = 2;
        }
    }

    void printVertices(int size, int **grid3x) {
        cout << "printing 3x grid..." << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) cout << grid3x[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};
