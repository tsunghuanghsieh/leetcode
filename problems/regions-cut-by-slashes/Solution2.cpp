#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC Editorial soln 3: disjoint set
    //
    // To union 2 sets, my initial implementation was to update the entire set to another using bfs,
    // since findParent() implementation simply returns the index when -1 is encountered or the value
    // contained, which will be topmost parent of the set. It is not as efficient as LC Editorial soln
    // 3 which uses daisy-chain appraoch to link topmost parents of 2 sets.
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
        vertices[0] = -1;   // the topmost parent of the border vertices
        // enumerate through the grid
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int idx1, idx2;
                if (grid[r][c] == ' ') continue;
                if (grid[r][c] == '/') {
                    idx1 = (r + slash_fwd[0][0]) * (n + 1) + c + slash_fwd[0][1];
                    idx2 = (r + slash_fwd[1][0]) * (n + 1) + c + slash_fwd[1][1];
                }
                else if (grid[r][c] == '\\') {
                    idx1 = (r + slash_bwd[0][0]) * (n + 1) + c + slash_bwd[0][1];
                    idx2 = (r + slash_bwd[1][0]) * (n + 1) + c + slash_bwd[1][1];
                }
                regions += findUnion(n + 1, vertices, idx1, idx2);
            }
        }
        return regions;
    }
private:
    const int slash_fwd[2][2] = {{1, 0}, {0, 1}};
    const int slash_bwd[2][2] = {{0, 0}, {1, 1}};

    int findParent(int *vertices, int idx) {
        if (vertices[idx] == -1) return idx;
        // keep going up the chain until -1 is encountered
        return vertices[idx] = findParent(vertices, vertices[idx]);
    }

    int findUnion(int size, int *vertices, int idx1, int idx2) {
        int parent1 = findParent(vertices, idx1);
        int parent2 = findParent(vertices, idx2);
        if (parent1 == parent2) return 1;   // loop encountered
        // daisy-chaining: update topmost parent of a set to that of the other set
        vertices[parent2] = parent1;
        return 0;
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
