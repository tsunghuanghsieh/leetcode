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
        //
        // LC Editorial explains using quickselect (Hoare's selection algorithm)
        // to find k-th (frequent/smallest/largest/etc) element, which has O(n) average time complexity,
        // but O(n^2) worst case time complexity. although probability of worst-case is negligible.
        // [Lomuto's Partition Scheme](https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme)
        for (int i = 0; i < k; i++) {
            res.emplace_back(q.top());
            q.pop();
        }
        return res;
    }
};
