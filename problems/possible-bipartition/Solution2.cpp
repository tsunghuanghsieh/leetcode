#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution2 {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1, vector<int>());
        vector<unordered_set<int>> partitions(2);
        queue<int> q;
        for (int i = 0; i < dislikes.size(); i++) {
            adj[dislikes[i][0]].emplace_back(dislikes[i][1]);
            adj[dislikes[i][1]].emplace_back(dislikes[i][0]);
        }

        for (int i = 1, cnt = 0; i < adj.size(); i++) {
            if (partitions[0].count(i) || partitions[1].count(i)) continue;
            partitions[cnt].insert(i);
            q.push(i);
            int q_size = q.size();

            while (q_size) {
                int num = q.front();
                q.pop();
                q_size--;
                for (int j = 0; j < adj[num].size(); j++) {
                    if (partitions[cnt].count(adj[num][j])) return false;
                    if (partitions[(cnt + 1) % 2].count(adj[num][j])) continue;
                    q.push(adj[num][j]);
                    partitions[(cnt + 1) % 2].insert(adj[num][j]);
                }
                if (q_size == 0) {
                    q_size = q.size();
                    cnt = (cnt + 1) % 2;
                }
            }
        }

        return true;
    }
};
