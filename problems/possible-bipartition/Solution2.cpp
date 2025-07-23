#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution2 {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<unordered_set<int>> adj(n + 1, unordered_set<int>());
        vector<unordered_set<int>> partitions(2);
        deque<int> dq;
        for (int i = 0; i < dislikes.size(); i++) {
            adj[dislikes[i][0]].insert(dislikes[i][1]);
            adj[dislikes[i][1]].insert(dislikes[i][0]);
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
                for (auto itr = adj[num].begin(); itr != adj[num].end(); itr++) {
                    if (partitions[cnt].count(*itr)) return false;
                    if (partitions[(cnt + 1) % 2].count(*itr)) continue;
                    dq.emplace_back(*itr);
                    partitions[(cnt + 1) % 2].insert(*itr);
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
