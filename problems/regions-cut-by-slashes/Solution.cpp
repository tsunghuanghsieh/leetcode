#include <iomanip>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // My approach is to treat the grid as a directed graph with vertices. Each forward and backward slash
    // has 2 vertices and each vertex has 4 possible directed edges which have a unique value (see below for
    // illustration). It enumerates through the vertices and use dfs for each encountered vertex to group
    // all connected vertices. From the disjoint sets of vertices, it will then determine the total number
    // of regions.
    // 4  1  ----
    //  \/   | /|   0 0 2
    //  /\   | \|   0 9 0
    // 2  8  ----   0 0 4
    //
    // LC Editorial soln 1 gives an idea to expand the grid by 3x (2x is too small and will cause confusion)
    // and line of the slashes will be marked as 1 while empty space is 0. In doing so, we can just count the
    // number of region 0s.
    //
    //  /\    0  0  1  1  0  0
    //  \/    0  1  0  0  1  0
    //        1  0  0  0  0  1
    //        0  1  0  0  1  0
    //        0  0  1  1  0  0
    //
    int regionsBySlashes(vector<string>& grid) {
        int regions = 1, n = grid.size();
        int group_idx = 0;

        int **vertices = new int *[n + 1];
        for (int i = 0; i <= n; i++) vertices[i] = new int[n + 1]();   // () to initialize to 0
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '/') {
                    vertices[r + 1][c] |= 1;
                    vertices[r][c + 1] |= 2;
                }
                else if (grid[r][c] == '\\') {
                    vertices[r][c] |= 8;
                    vertices[r + 1][c + 1] |= 4;
                }
            }
        }
        for (int r = 0; r <= n; r++) {
            for (int c = 0; c <= n; c++) {
                if (vertices[r][c] == 0 || visited.count(r * (n + 1) + c) > 0) continue;
                regions += dfs(n + 1, vertices, r, c, -1, -1, group_idx) / 2;
                if (group_idx < countVerticesOnBorder.size()) group_idx++;
            }
        }
        for (int i = 0; i < countVerticesOnBorder.size(); i++) {
            regions += (countVerticesOnBorder[i] - 1);
        }
        return regions;
    }
private:
    static const int DIRS_COUNT = 4, COUNT_TWO = 2;
    unordered_set<int> visited;
    int dirs[DIRS_COUNT][COUNT_TWO] = {{-1, 1}, {1, -1}, {-1, -1}, {1, 1}};   // ne, sw, nw, se
    int dirs_value[DIRS_COUNT] = {1, 2, 4, 8};   // ne, sw, nw, se
    vector<int> countVerticesOnBorder;
    int dfs(int size, int **vertices, int r, int c, int prev_r, int prev_c, int group_idx) {
        int region = 0;
        visited.insert(r * size + c);
        for (int d = 0; d < DIRS_COUNT; d++) {
            if ((vertices[r][c] & dirs_value[d]) == 0) continue;
            int adj_r = r + dirs[d][0], adj_c = c + dirs[d][1];
            if (adj_r == prev_r && adj_c == prev_c) continue;   // parent vertex
            if (visited.count(adj_r * size + adj_c) > 0) {   // loop formed
                region++;
                continue;
            }
            region += dfs(size, vertices, adj_r, adj_c, r, c, group_idx);
        }
        if (r == 0 || r == size - 1 || c == 0 || c == size - 1) {
            if (countVerticesOnBorder.size() == group_idx) countVerticesOnBorder.push_back(1);
            else countVerticesOnBorder[group_idx]++;
        }
        return region;
    }

    void printGrid(vector<string>& grid) {
        cout << "printing grid..." << endl;
        for (int i = 0; i < grid.size() + 2; i++) cout << "-";
        cout << endl;
        for (string s : grid) cout << "|" << s << "|" << endl;
        for (int i = 0; i < grid.size() + 2; i++) cout << "-";
        cout << endl;
    }

    void printVertices(int size, int **vertices) {
        cout << "printing vertices..." << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) cout << setw(2) << std::fixed << vertices[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};
