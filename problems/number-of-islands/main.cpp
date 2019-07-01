#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
using namespace std;

class Solution
{
private:
    map<pair<int, int>, int> islands;

    void deleteAdjacent(int rows, int cols, pair<int, int> center)
    {
        set<pair<int, int>> adjacent;
        adjacent.insert(center);

        while (!adjacent.empty()) {
            auto itr = adjacent.begin();
            pair<int, int> toDelete = *itr;
            if (islands.find(toDelete) != islands.end()) islands.erase(toDelete);
            adjacent.erase(toDelete);
            for (int row = toDelete.first -1; row <= toDelete.first + 1; row++)
            {
                if (row < 0 || row >= rows) continue;
                pair<int, int> coor = {row, toDelete.second};
                if (islands.find(coor) != islands.end()) adjacent.insert(coor);
            }
            for (int col = toDelete.second -1; col <= toDelete.second + 1; col++)
            {
                if (col < 0 || col >= cols) continue;
                pair<int, int> coor = {toDelete.first, col};
                if (islands.find(coor) != islands.end()) adjacent.insert(coor);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == '1')
                {
                    pair<int, int> coor = {row, col};
                    islands[coor] = 1;
                }
            }
        }
        int count = 0;
        while (islands.size() > 0)
        {
            map<pair<int, int>, int>::iterator itr = islands.begin();
            count++;
            pair<int, int> key = itr->first;
            deleteAdjacent(rows, cols, key);
            itr = next(itr);
        }
        return count;
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