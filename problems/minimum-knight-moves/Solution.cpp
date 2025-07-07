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
    //
    // LC Editorial brings up symmetry property of solutions. It takes the same number of
    // steps to reach [2, 1], [-2, 1], [2, -1], [-2, -1]. Hence, we can simply find the
    // steps of [|x|, |y|] in the first quadrant.
    //
    // LC Editorial soln #3; It's more efficient using dfs going from [x, y] to [0, 0],
    // dirs can then be reduced to [-1, -2] and [-2, -1] with terminating conditions that
    // returns 0 at [0, 0] and 2 at [1, 2] and [2, 1].
    int minKnightMoves(int x, int y) {
        const int bound = 300;
        bool visited[bound + 1][bound + 1] = {};   // init to 0
        x = abs(x);
        y = abs(y);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        int size = q.size(), steps = 0;
        while (size > 0) {
            pair<int, int> curr = q.front();
            if (curr.first == x && curr.second == y) break;
            q.pop();
            size--;
            for (int i = 0; i < 8; i++) {
                int new_x = abs(curr.first + dirs[i][0]), new_y = abs(curr.second + dirs[i][1]);
                if (new_x > bound || new_y > bound) continue;
                if (abs(new_x) + abs(new_y) > bound) continue;
                if (visited[new_x][new_y]) continue;
                visited[new_x][new_y] = true;
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
