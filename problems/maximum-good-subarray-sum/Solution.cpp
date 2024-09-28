#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> vals_last;
        unordered_set<int> seen;
        vector<int> k2 = {k, -k};
        long sum = LONG_MIN;
        // index of last occurrence of the numbers
        for (int i = 0; i < nums.size(); i++) vals_last[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) {
            // skipping repeated numbers
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            for (int k = 0; k < 2; k++) {
                // finding |nums[i] - nums[j]| == k
                if (vals_last.count(nums[i] + k2[k])) {
                    // skipping indices before i
                    if (vals_last[nums[i] + k2[k]] < i) continue;
                    long temp = 0;
                    // calculating running sum between nums[j] and nums[i] (backward) where j >= i
                    for (int last = vals_last[nums[i] + k2[k]], j = last; j >= i; j--) {
                        temp += nums[j];
                        // duplicated number of nums[i], update sum if running sum is larger than nums[i]
                        if (nums[j] == nums[i] && temp > sum) sum = temp;
                        // duplicated number of nums[j], reset temp if running sum is smaller than nums[j]
                        if (nums[last] == nums[j] && temp < nums[last]) temp = nums[last];
                    }
                }
            }
        }
        return (sum == LONG_MIN) ? 0 : sum;
    }
};
