#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // Second iteration uses prefix sum to eliminate repeated sum calculations. It stil runs through
    // all combinations of indices of nums[i] and nums[j]. However, empirical evidence on LC platform
    // shows longer execution time using unordered_map<int, vector<int>>, vs unordered_map<int, int>.
    // It encountered TLE error.
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> vals_indices;
        unordered_set<int> seen;
        vector<int> k2 = {k, -k};
        vector<long> prefix_sums;
        long sum = LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            vals_indices[nums[i]].emplace_back(i);
            prefix_sums.emplace_back(nums[i]);
            if (i > 0) prefix_sums[i] += prefix_sums[i - 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            for (int k = 0; k < 2; k++) {
                int target = nums[i] + k2[k];
                if (vals_indices.count(target)) {
                    for (int ii = 0; ii < vals_indices[nums[i]].size(); ii++) {
                        for (int j =  0; j < vals_indices[target].size(); j++) {
                            if (vals_indices[nums[i]][ii] > vals_indices[target][j]) continue;
                            long temp = prefix_sums[vals_indices[target][j]] -
                                prefix_sums[vals_indices[nums[i]][ii]] + nums[i];
                            if (temp > sum) sum = temp;
                        }
                    }
                }
            }
        }
        return (sum == LONG_MIN) ? 0 : sum;
    }
};
