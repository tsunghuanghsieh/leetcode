#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    // LC Editorial soln #1: bfs
    // LC Editorial soln #2: bidirectional bfs
    // LC Editorial soln #3: dfs
    //
    // The improved bfs implementation uses queue<pair<int, int>> for steps and bool[][].
    // This is similar to LC Editorial soln #1.
    int minKnightMoves(int x, int y) {
        const int offset = 300, bound = 300;
        bool visited[2 * bound + 1][2 * bound + 1] = {};   // init to 0
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[offset][offset] = true;
        int size = q.size(), steps = 0;
        while (size > 0) {
            pair<int, int> curr = q.front();
            if (curr.first == x && curr.second == y) break;
            q.pop();
            size--;
            for (int i = 0; i < 8; i++) {
                int new_x = curr.first + dirs[i][0], new_y = curr.second + dirs[i][1];
                if (new_x > bound || new_x < -bound || new_y > bound || new_y < -bound) continue;
                if (abs(new_x) + abs(new_y) > bound) continue;
                if (visited[new_x + offset][new_y + offset]) continue;
                visited[new_x + offset][new_y + offset] = true;
                q.push({new_x, new_y});
            }
            if (size == 0) {
                size = q.size();
                steps++;
            }
        }
        return steps;
    }
private:
    const int dirs[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
};
