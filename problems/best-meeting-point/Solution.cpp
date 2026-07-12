#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln 1: bfs uses brute force to determine the minimum distance to every cell from friends,
    // and will result in TLE.
    // The runtime complexity is O((mn)^2) and space complexity O(mn).
    int minTotalDistance(vector<vector<int>>& grid) {
        int shortest = 0;
        vector<pair<int, int>> houses;
        row_size = grid.size();
        col_size = grid[0].size();
        distances.resize(row_size, vector<int>(col_size));

        for (int r = 0; r < row_size; r++) {
            for (int c = 0; c < col_size; c++) {
                if (grid[r][c] == 1) {
                    houses.emplace_back(pair<int, int>{r, c});
                    grid[r][c] = 0;
                }
            }
        }

        for (int h = 0; h < houses.size(); h++) {
            shortest = bfs(houses[h].first, houses[h].second, h, grid);
        }
        return shortest;
    }
private:
    int row_size = 0, col_size = 0;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> distances;

    int bfs(int r, int c, int h, vector<vector<int>>& grid) {
        int shortest = INT_MAX;
        vector<pair<int, int>> curr, next;
        curr.emplace_back(pair<int, int>{r, c});
        for (int i = 0, step = 1; i < curr.size(); i++) {
            grid[r][c] = h + 1;
            for (int d = 0; d < 4; d++) {
                int dr = curr[i].first + dirs[d][0], dc = curr[i].second + dirs[d][1];
                if (dr < 0 || dr >= row_size || dc < 0 || dc >= col_size || grid[dr][dc] == h + 1) continue;
                grid[dr][dc] = h + 1;
                distances[dr][dc] += step;
                shortest = min(shortest, distances[dr][dc]);
                next.emplace_back(pair<int, int>{dr, dc});
            }
            if (i + 1 == curr.size()) {
                curr.swap(next);
                next = {};
                i = -1;
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
