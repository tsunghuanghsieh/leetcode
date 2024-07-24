#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int shortest = INT_MAX;
        row_size = grid.size();
        col_size = grid[0].size();
        grid1d.resize(row_size * col_size);
        unordered_set<int> pos0s, pos1s;
        unordered_set<int> visited;

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == 0) pos0s.insert(i * col_size + j);
                else visited.insert(i * col_size + j);
                if (grid[i][j] == 1) pos1s.insert(i * col_size + j);
            }
        }

        if (pos0s.size() == 0) return -1;

        for (int pos : pos1s) {
            // do bfs from each building to determine distance from all empty space in the grid
            bfs(pos, grid, pos0s, visited);
        }
        for (int pos : pos0s) {
            shortest = min(shortest, grid1d[pos]);
        }
        return (shortest != INT_MAX) ? shortest : -1;
    }
private:
    int row_size, col_size;
    vector<int> grid1d;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   // up, right, down, left
    void bfs(int pos, const vector<vector<int>>& grid, unordered_set<int> pos0s, unordered_set<int> visited) {
        vector<int> distances(row_size * col_size, INT_MAX);
        queue<int> q;
        q.push(pos);
        int qsize = q.size(), step = 1;
        visited.insert(pos);
        while (qsize > 0) {
            int val = q.front(), r = val / col_size, c = val % col_size;
            q.pop();
            qsize--;
            for (vector<int> dir : dirs) {
                int dr = r + dir[0], dc = c + dir[1], adj = dr * col_size + dc;
                if (visited.count(adj) > 0 || dr < 0 || dr >= row_size || dc < 0 || dc >= col_size) continue;
                distances[adj] = min(distances[adj], step);
                q.push(adj);
                visited.insert(adj);
            }
            if (qsize == 0) {
                qsize = q.size();
                step++;
            }
        }
        for (int pos : pos0s) {
            grid1d[pos] = (distances[pos] == INT_MAX || grid1d[pos] == INT_MAX) ? INT_MAX : grid1d[pos] + distances[pos];
        }
    }

    void printGrid(vector<int>& distances) {
        for (int pos = 0; pos < distances.size(); pos++) {
            if (pos % col_size == 0) cout << endl;
            if (distances[pos] != INT_MAX) cout << distances[pos] << " ";
            else cout << "  ";
        }
        cout << endl << endl;
    }
};
