#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC Editorial soln #1: bsf
    //
    // This approach will first iterate through dislikes once to store their relationships
    // in vector<vector<int>> adj. After that, it can perform bfs. One key takeaway is that
    // adjacent neighbors will be in different partitions, or in LC soln, different colors.
    // My initial implementation was literally 2 partitions, using vector<unordered_set<int>>.
    // However, it can use vector<int>, with value 0 and 1 for partitions, which is cleaner.
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> partitions(n + 1, -1);
        queue<int> q;
        for (int i = 0; i < dislikes.size(); i++) {
            adj[dislikes[i][0]].emplace_back(dislikes[i][1]);
            adj[dislikes[i][1]].emplace_back(dislikes[i][0]);
        }

        for (int i = 1, cnt = 0; i < adj.size(); i++) {
            if (partitions[i] != -1) continue;
            partitions[i] = 0;   // partition 0
            q.push(i);

            while (!q.empty()) {
                int num = q.front();
                q.pop();
                for (int j = 0; j < adj[num].size(); j++) {
                    if (partitions[num] == partitions[adj[num][j]]) return false;
                    if (partitions[adj[num][j]] != -1) continue;
                    q.push(adj[num][j]);
                    partitions[adj[num][j]] = 1 - partitions[num];   // alternate partition
                }
            }
        }

        return true;
    }
};
