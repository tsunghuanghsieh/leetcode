#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size() - 1;   // 0-based index
        n = grid[0].size() - 1;   // 0-based index
        if (k >= m + n) return m + n;   // special case: shortest (manhattahn) distance
        visited.reserve((m + 1) * (n + 1));   // Let STL pick the right bucket count
        priority_queue<vector<int>> q;   // max heap
        visited.insert({0, 0, k});   // row, col, available k at [row, col]
        q.push({0, 0, k});   // row, col, available k at [row, col]
        int steps = bfs(grid, visited, q, 0);
        return steps;
    }
private:
    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};   // e, s, w, n
    int m, n;
    struct hashFn {
        size_t operator()(const std::vector<int>& v) const {
            // generating unique hash
            // same hash for same row and col, regardless of k
            // otherwise unordered_set.count() will return false for the same cell with diff k
            // nuance of count(): hashFn(a) == hashFn(b) and equalFn(a) == equalFn(b)
            // row, col, available k at [row, col]
            return (v[0] + 1) * (v[1] + 1);
        }
    };
    struct equalFn {
        bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
            // To fulfill commutative property: equalFn(a, b) == equalFn(b, a)
            // only consider row and col and NOT available k so that it can handle >, < and == individually
            // otherwise, only a[2] == b[2] will be excluded.
            // Processing incoming vector with smaller available k is not necessary.
            // row, col, available k at [row, col]
            return a[0] == b[0] && a[1] == b[1];
        }
    };
    unordered_set<vector<int>, hashFn, equalFn> visited;

    // Evaluate to false to add v to the priority_queue
    // If v[0] and v[1] exist in the set and v's k, v[2], is larger, we want to remove it
    // since it cannot be updated in place while it's in the set
    bool checkDominance(unordered_set<vector<int>, hashFn, equalFn>& visited, const std::vector<int>& v) {
        auto itr = visited.find(v);
        if (itr == visited.end()) return false;
        // row, col, available k at [row, col]
        if ((*itr)[2] >= v[2]) return true;   // v is worse, exclude from being added to the priority_queue
        visited.erase(itr);
        return false;
    }

    int bfs(vector<vector<int>>& grid, unordered_set<vector<int>, hashFn, equalFn>& visited,
        priority_queue<vector<int>>& curr, int steps) {
        priority_queue<vector<int>> next;
        while (curr.size() > 0) {
            auto [row, col, avail_k] = tuple{curr.top()[0], curr.top()[1], curr.top()[2]};
            curr.pop();
            if (row == m & col == n) return steps;
            for (int d = 0; d < 4; d++) {
                int nextRow = row + dirs[d][0], nextCol = col + dirs[d][1];
                if (0 > nextRow || m < nextRow || 0 > nextCol || n < nextCol) continue;   // bound check
                bool hasObs = grid[nextRow][nextCol];
                std::vector<int> v({nextRow, nextCol, avail_k - hasObs});
                if (avail_k - hasObs < 0) continue;   // brickwalled, k exhausted
                // Instead of visited.count(v) which, if considering available k, will evaluate
                // to false when v's k, v[2], is different and allow v into the priority_queue,
                // I used a separate to fine tune the behavior and only allow it when it's larger.
                else if(checkDominance(visited, v)) continue;
                next.push({nextRow, nextCol, avail_k - hasObs});
                visited.insert(v);
            }
        }
        return (next.size()) ? bfs(grid, visited, next, steps + 1) : -1;
    }
};
