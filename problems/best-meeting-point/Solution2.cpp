#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC Editorial soln 3: breaks down the problem into 1D arrays, vertical (rows) and horizontal (cols).
    // For example,
    //   0 1 2 3 4
    // 0 1 0 0 0 1
    // 1 0 0 0 0 0
    // 2 0 0 1 0 0
    //
    // rows [0, 0, 2]
    // cols [0, 4, 2]
    // The best meeting point will be the median of the 2 arrays. With even friends, there will be 2 solns.
    //
    // The runtime complexity is O(mn + nlogn) and space complexity O(mn).
    //
    // LC Editorial soln 4, instead of doing 1 time m * n to get both rows (in order) and cols (out of order).
    // It does the loop twice so it can get cols in order. That will improve runtime complexity to O(mn).
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    rows.emplace_back(r);
                    cols.emplace_back(c);   // not necessary in order
                }
            }
        }
        sort(cols.begin(), cols.end());
        int coor_x = rows[rows.size() / 2], coor_y = cols[cols.size() / 2];
        return minTotalDistance(rows, coor_x) + minTotalDistance(cols, coor_y);
    }
private:
    int minTotalDistance(vector<int> v, int median) {
        int distance{};
        for (int i = 0; i < v.size(); i++) {
            distance += abs(v[i] - median);
        }
        return distance;
    }
};
