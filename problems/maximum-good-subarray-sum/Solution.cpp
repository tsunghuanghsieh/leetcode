#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // Second iteration uses prefix sum to eliminate repeated sum calculations. It stil runs through
    // all combinations of indices of nums[i] and nums[j]. It encountered TLE error on LC platform.
    // Without breakdown of the test cases exeuction time, I cannot conclusively determine the exact
    // cause of TLE:
    // 1) the length of repeated numbers in test cases
    // 2) the execution time of unordered_map<int, vector<int>> vs unordered_map<int, int>
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> seen_psums;   // key: number, value: min prefix sum of the number
        vector<long long> prefix_sums;
        long long sum = LLONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            // prefix sum for nums[i]
            prefix_sums.emplace_back(nums[i]);
            if (i > 0) prefix_sums[i] += prefix_sums[i - 1];

            // sum of nums[i] and nums[j]
            int target1 = nums[i] + k;
            if (seen_psums.count(target1)) sum = max(sum, prefix_sums[i] - seen_psums[target1] + target1);
            int target2 = nums[i] - k;
            if (seen_psums.count(target2)) sum = max(sum, prefix_sums[i] - seen_psums[target2] + target2);

            // keep track of the minimum prefix sum for nums[i]
            if (seen_psums.count(nums[i])) {
                seen_psums[nums[i]] = min(seen_psums[nums[i]], prefix_sums[i]);
            }
            else {
                seen_psums[nums[i]] = prefix_sums[i];
            }
        }
        return (sum == LONG_MIN) ? 0 : sum;
    }
};
