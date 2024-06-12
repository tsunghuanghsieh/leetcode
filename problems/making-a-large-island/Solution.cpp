#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    // Update 1s in grid in place with island identifier using dfs.
    // Tried using adjacents set to reduce the number of 0s to compare.
    // Empirical data shows that time for set inserts, O(NlogN), adds up when the number is in 10s of 1000.
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int island_id = 2, largest = 0;
        vector<int> islands(n * n);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    // dfs of current island and set value to index
                    islands[island_id - 2] = dfs(grid, island_id, row, col);
                    island_id++;
                }
            }
        }
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int count = 1;
                set<int> dirs;
                if (grid[row][col] != 0) continue;
                for (int d = 0; d < 4; d++) {
                    auto coor = goDirection(Direction(d), row, col);
                    if (!isInBound(coor, grid.size())) continue;
                    if (grid[coor.first][coor.second] != 0) dirs.insert(grid[coor.first][coor.second] - 2);
                }
                for (int i : dirs) count += islands[i];
                largest = max(largest, count);
            }
        }
        // largest is 0 when the grid has no 0s
        return (largest) ? largest : n * n;
    }

    // helper function to help visualize grid on console
    void printGrid(vector<vector<int>> grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
private:
    enum Direction { WEST = 0, NORTH = 1, EAST = 2, SOUTH = 3};
    const vector<pair<int, int>> movements = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};   // west, north, east, south

    int dfs(vector<vector<int>>& grid, const int island_id, int row, int col) {
        int count = 1;
        grid[row][col] = island_id;
        for (int d = 0; d < 4; d++) {
            auto coor = goDirection(Direction(d), row, col);
            if (!isInBound(coor, grid.size()) || grid[coor.first][coor.second] != 1) continue;
            count += dfs(grid, island_id, coor.first, coor.second);
        }
        return count;
    }

    inline pair<int, int> goDirection(const Direction dir, const int &row, const int &col) {
        return {row + movements[dir].first, col + movements[dir].second};
    }

    inline bool isInBound(pair<int, int> coor, int dimension) {
        return (coor.first < 0 || coor.first == dimension ||
                coor.second < 0 || coor.second == dimension) ? false : true;
    }
};
