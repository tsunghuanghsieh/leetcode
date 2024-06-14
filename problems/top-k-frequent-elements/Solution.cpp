#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        priority_queue<pair<int, int>> q;

        // count occurrence and piggyback q updates on the loop
        for (int n : nums) {
            um[n]++;
            q.push(pair{um[n], n});
        }
        vector<int> res;
        // find k frequent elements
        while (!q.empty() && k > 0) {
            pair<int, int> p = q.top();
            if (um.find(p.second) != um.end()) {
                res.emplace_back(p.second);
                um.erase(p.second);
                k--;
            }
            q.pop();
        }
        return res;
    }
};
