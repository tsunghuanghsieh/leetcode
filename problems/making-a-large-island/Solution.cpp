#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<set<pair<int, int>>> islands;
        set<pair<int, int>> seen, adjacents;
        queue<pair<int, int>> coors;

        printGrid(grid);
        coors.push({0, 0});
        // bfs to identify all islands in the grid, O(n^2)
        while (coors.size() > 0) {
            int row = coors.front().first, col = coors.front().second;
            coors.pop();

            // Comparing each element against all islands get really slow when the number is big, say 10s of 1k.
            // Similarly, insert to islands and adjacents sets takes longer.
            processGrid(n, row, col, grid[row][col], islands, adjacents);
            if (isInBound(goDirection(Direction::EAST, row, col), n) &&
                seen.count(goDirection(Direction::EAST, row, col)) == 0) {
                coors.push(goDirection(Direction::EAST, row, col));
                seen.insert(goDirection(Direction::EAST, row, col));
            }
            if (isInBound(goDirection(Direction::SOUTH, row, col), n) &&
                seen.count(goDirection(Direction::SOUTH, row, col)) == 0) {
                coors.push(goDirection(Direction::SOUTH, row, col));
                seen.insert(goDirection(Direction::SOUTH, row, col));
            }
        }
        if (islands.size() == 0) return 1;
        if (islands.size() == 1) return min(int(islands[0].size() + 1), n * n);
        // Comparing all adjacents against all islands takes a long time when the number is big, say 10s of 1k.
        return findLargest(n, adjacents, islands);
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

    int findLargest(int size, set<pair<int, int>>& adjacents, vector<set<pair<int, int>>>& islands) {
        int largest = 0;
        for (auto p : adjacents) {
            int total = 1;
            vector<int> indices(islands.size(), 0);
            for (int d = 0; d < 4; d++) {
                auto coor = goDirection(Direction(d), p.first, p.second);
                if (!isInBound(coor, size)) continue;
                for (int i = 0; i < islands.size(); i++) {
                    if (islands[i].count(coor) > 0 && indices[i] == 0) {
                        indices[i] = 1;
                        total += islands[i].size();
                    }
                }
            }
            largest = max(largest, total);
        }
        return largest;
    }

    inline pair<int, int> goDirection(const Direction dir, const int &row, const int &col) {
        return {row + movements[dir].first, col + movements[dir].second};
    }

    inline bool isInBound(pair<int, int> coor, int dimension) {
        return (coor.first < 0 || coor.first == dimension ||
                coor.second < 0 || coor.second == dimension) ? false : true;
    }

    void processGrid(int size, int row, int col, int val, vector<set<pair<int, int>>>& islands, set<pair<int, int>>& adjacents) {
        int prevIsland = -1;
        for (int d = 0; d < 2; d++) { // just need to check west and north. we haven't sesen east and south yet.
            auto coor = goDirection(Direction(d), row, col);
            if (!isInBound(coor, size)) continue;
            for (int i = 0, count = 0; i < islands.size(); i++) {
                if (islands[i].count(coor) > 0) {
                    count++;
                    if (val == 1) {
                        if (prevIsland < 0) {
                            prevIsland = i;
                            islands[prevIsland].insert(make_pair(row, col));
                        }
                        else {
                            if (prevIsland != i) {
                                // different island
                                mergeIslands(islands[prevIsland], islands[i]);
                                islands.erase(islands.begin() + i);
                            }
                            return;
                        }
                        break;
                    }
                    else {
                        adjacents.insert({row, col});
                    }
                }
                else {
                    if (i + 1 == islands.size() && val == 1 && count == 0) {
                        adjacents.insert(coor);
                    }
                }
            }
        }
        if (val == 1 && prevIsland == -1) {
            set<pair<int, int>> island({make_pair(row, col)});
            islands.push_back(island);
        }
    }

    // Helper function to merge 2 islands into 1 and reset fromIsland
    void mergeIslands(set<pair<int, int>>& toIsland, set<pair<int, int>>& fromIsland) {
        if (toIsland.size() < fromIsland.size()) toIsland.swap(fromIsland);
        toIsland.insert(fromIsland.begin(), fromIsland.end());
        set<pair<int, int>> empty;
        fromIsland.swap(empty);
    }

    // Helper function for validation
    void listAdjacents(const set<pair<int, int>>& adjacents) {
        for (auto p : adjacents) {
            cout << p.first << " " << p.second << endl;
        }
    }

    // Helper function for validation
    void listIslands(vector<set<pair<int, int>>>& islands) {
        for (int i = 0; i < islands.size(); i++) {
            cout << "i " << i << " size " << islands[i].size() << endl;
        }
    }
};
