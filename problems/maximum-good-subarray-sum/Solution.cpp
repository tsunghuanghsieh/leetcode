#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // The first thing to recognize for this problem should be prefix sum. The sum from nums[target] to
    // nums[i] can then be calculated using (prefix_sum[i] - prefix_sums[seen_psums[target1]] + target),
    // where i is the current index, target is (nums[i] +/- k), prefix_sum[i] is the prefix sum at index
    // i and seen_psum is an unordered_map of target (key) to the index of the minimum prefix sum of
    // target to up index i (value). Since the index of the minimum prefix sum may change over i, the sum
    // will have to be calculated for all nums[i] using the current prefix sum, prefix_sum[i].
    //
    // The naive implmenetaion is to get all prefix sums in the first pass, then set the minimum prefix
    // sum of nums[i] and the sum from nums[target] and nums[i] in the second pass. However, an improved
    // implmenetation is to combine them in a single pass since the operations that would have been done
    // in the second pass at index i only require output from the first pass up to index i.
    //
    // Third iteration: runtime and space complexity O(n)
    // Instead of getting all indices of a number in the first pass and looking forward to get all
    // combinations of prefix sum of nums[i] and nums[j] in the second pass as in the second iteration,
    // it keeps track of the index of the minimum prefix sum of the current number encountered, while
    // comparing the minimum prefix sum of (currnet number +/- k) against the prefix sum of the current
    // number, all in the same pass.
    //
    // Second iteration uses prefix sum to eliminate repeated sum calculations. It stil runs through
    // all combinations of indices of nums[i] and nums[j]. It encountered TLE error on LC platform.
    // Without breakdown of the test cases exeuction time, I cannot conclusively determine the exact
    // cause of TLE:
    // 1) the length of repeated numbers in test cases
    // 2) the execution time of unordered_map<int, vector<int>> vs unordered_map<int, int>
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen_psums;   // key: number, value: index of min prefix sum of the number
        vector<long long> prefix_sums;
        long long sum = LLONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            // prefix sum for nums[i]
            prefix_sums.emplace_back(nums[i]);
            if (i > 0) prefix_sums[i] += prefix_sums[i - 1];

            // sum of nums[i] and nums[j]
            int target1 = nums[i] + k;
            if (seen_psums.count(target1)) sum = max(sum, prefix_sums[i] - prefix_sums[seen_psums[target1]] + target1);
            int target2 = nums[i] - k;
            if (seen_psums.count(target2)) sum = max(sum, prefix_sums[i] - prefix_sums[seen_psums[target2]] + target2);

            // keep track of the minimum prefix sum for nums[i]
            if (seen_psums.count(nums[i])) {
                seen_psums[nums[i]] = (prefix_sums[seen_psums[nums[i]]] > prefix_sums[i]) ? i : seen_psums[nums[i]];
            }
            else {
                seen_psums[nums[i]] = i;
            }
        }
        return (sum == LONG_MIN) ? 0 : sum;
    }
};
