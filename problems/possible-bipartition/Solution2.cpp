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
        deque<int> dq;
        for (int i = 0; i < dislikes.size(); i++) {
            adj[dislikes[i][0]].emplace_back(dislikes[i][1]);
            adj[dislikes[i][1]].emplace_back(dislikes[i][0]);
        }

        for (int i = 1, cnt = 0; i < adj.size(); i++) {
            if (partitions[0].count(i) || partitions[1].count(i)) continue;
            partitions[cnt].insert(i);
            dq.emplace_back(i);
            int dq_size = dq.size();

            while (dq_size) {
                int num = dq.front();
                dq.pop_front();
                dq_size--;
                for (int j = 0; j < adj[num].size(); j++) {
                    if (partitions[cnt].count(adj[num][j])) return false;
                    if (partitions[(cnt + 1) % 2].count(adj[num][j])) continue;
                    dq.emplace_back(adj[num][j]);
                    partitions[(cnt + 1) % 2].insert(adj[num][j]);
                }
                if (dq_size == 0) {
                    dq_size = dq.size();
                    cnt = (cnt + 1) % 2;
                }
            }
        }

        return true;
    }
};
