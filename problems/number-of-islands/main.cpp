#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
using namespace std;

class Solution
{
private:
    void bfs(vector<vector<char>> &grid, pair<int, int> center) {
        queue<pair<int, int>> island;
        island.push(center);
        int rows = grid.size();
        int cols = grid[0].size(); // assuming same width across all rows

        // BFS
        while (!island.empty()) {
            pair<int, int> adjacents = island.front();
            island.pop();
            grid[adjacents.first][adjacents.second] = '2'; // visited
            // directions: left, down, right, up.
            pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            for (int i = 0; i < 4; i++) {
                int row = adjacents.first + dirs[i].first;
                int col = adjacents.second + dirs[i].second;
                if (row < 0 || row >= rows || col < 0 || col >= cols) continue;
                if (grid[row][col] == '1') {
                    island.push(make_pair(row, col));
                    grid[row][col] = '2'; // visited
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0) return 0;
        int total = 0;
        int rows = grid.size();
        int cols = grid[0].size(); // assuming same width across all rows
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == '1') {
                    bfs(grid, make_pair(row, col));
                    total++;
                }
            }
        }
        return total;
    }
};

int main()
{
    Solution s;
    auto grid = vector<vector<char>>({
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
        });
    s.numIslands(grid);
    return 0;
}