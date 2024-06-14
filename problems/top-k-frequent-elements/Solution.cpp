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
        // compare function for priority_queue
        auto comp = [&um] (int a, int b) {
            // incoming > existing for max heap
            return um[b] > um[a];
        };
        priority_queue<int, vector<int>, decltype(comp)> q(comp);

        // count frequency
        for (int n : nums) {
            um[n]++;
        }
        vector<int> res;
        // populate q with element index according to frequency
        for (auto [key, val] : um) {
            q.emplace(key);
        }
        // find k frequent elements
        for (int i = 0; i < k; i++) {
            res.emplace_back(q.top());
            q.pop();
        }
        return res;
    }
};
