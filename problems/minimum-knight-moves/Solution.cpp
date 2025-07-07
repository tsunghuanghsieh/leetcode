#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // LC Editorial soln #1: bfs
    // LC Editorial soln #2: bidirectional bfs
    // LC Editorial soln #3: dfs
    //
    // The initial naive bfs implementation uses queue<pair<int, int>> for steps and slow
    // unordered_set<pair<int, int>> which requires custom hash function. This is similar
    // but less efficient than LC Editorial soln #1 due to data structure used.
    int minKnightMoves(int x, int y) {
        unordered_set<pair<int, int>, hashFn> visited;
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited.insert({0, 0});
        int size = q.size(), steps = 0;
        while (size > 0) {
            pair<int, int> curr = q.front();
            if (curr.first == x && curr.second == y) break;
            q.pop();
            size--;
            for (int i = 0; i < 8; i++) {
                int new_x = curr.first + dirs[i][0], new_y = curr.second + dirs[i][1];
                if (new_x > 300 || new_x < -300 || new_y > 300 || new_y < -300) continue;
                if (abs(new_x) + abs(new_y) > 300) continue;
                if (visited.count({new_x, new_y})) continue;
                visited.insert({new_x, new_y});
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
    struct hashFn {
        size_t operator()(const std::pair<int, int>& p) const {
            // generating unique hash
            return (p.first + 1) * (p.second + 1);
        }
    };
};
