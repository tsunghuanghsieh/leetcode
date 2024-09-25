#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC Editorial soln 3: disjoint set
    int regionsBySlashes(vector<string>& grid) {
        int regions = 1, n = grid.size(), vertices_size = (n + 1) * (n + 1);

        // value in vertices is the position of its parent vertex
        int *vertices = new int [vertices_size];
        for (int r = 0; r <= n; r++) {
            for (int c = 0; c <= n; c++) {
                // border of the vertices: their parent is (0, 0), top left cell
                if (r == 0 || r == n || c == 0 || c == n) vertices[r * (n + 1) + c] = 0;
                // initialize the rest to -1
                else vertices[r * (n + 1) + c] = -1;
            }
        }
        // enumerate through the grid
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int idx1r = 0, idx1c = 0, idx2r = 0, idx2c = 0;
                if (grid[r][c] == ' ') continue;
                if (grid[r][c] == '/') {
                    idx1r = r + slash_fwd[0][0], idx1c = c + slash_fwd[0][1];
                    idx2r = r + slash_fwd[1][0], idx2c = c + slash_fwd[1][1];
                }
                else if (grid[r][c] == '\\') {
                    idx1r = r + slash_bwd[0][0], idx1c = c + slash_bwd[0][1];
                    idx2r = r + slash_bwd[1][0], idx2c = c + slash_bwd[1][1];
                }
                int parent1 = findParent(vertices, idx1r * (n + 1) + idx1c);
                int parent2 = findParent(vertices, idx2r * (n + 1) + idx2c);
                if (parent1 == parent2) regions++;
                else {
                    if (parent1 > parent2) findUnion(n + 1, vertices, parent1, parent2, idx1r, idx1c);
                    else findUnion(n + 1, vertices, parent2, parent1, idx2r, idx2c);
                }
            }
        }
        return regions;
    }
private:
    const int dirs[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    const int slash_fwd[2][2] = {{1, 0}, {0, 1}};
    const int slash_bwd[2][2] = {{0, 0}, {1, 1}};

    int findParent(int *vertices, int idx) {
        if (vertices[idx] == -1) return vertices[idx] = idx;
        return vertices[idx];
    }

    void findUnion(int size, int *vertices, int fromParent, int toParent, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            vertices[r * size + c] = toParent;
            for (int d = 0; d < 4; d++) {
                int adj_r = r + dirs[d][0], adj_c = c + dirs[d][1];
                int adj_idx = adj_r * size + adj_c;
                if  (vertices[adj_idx] == fromParent) {
                    q.push({adj_r, adj_c});
                }
            }
        }
    }

    void printVertices(int size, int *vertices) {
        cout << "printing vertices..." << endl;
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) cout << setw(2) << std::fixed << vertices[r * size + c] << " ";
            cout << endl;
        }
        cout << endl;
    }
};
