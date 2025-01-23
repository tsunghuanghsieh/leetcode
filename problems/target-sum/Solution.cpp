#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // The approach is the same as LC Editorial soln #4.
    // The initial approach, commented out at the bottom, was to use unordered_map<int, int> to keep
    // track of the sums at the current index and the number of ways to arrive at the sum. It is simpler
    // however it takes longegr to execute compared to vector<int>.
    //
    // Runtime complexity O(n * totalSum), space complexity is ~O(totalSum)
    //
    // using vector<pair<int, int>> takes longer to execute than vector<int> with hardcoded size,
    // even slower than unordered_map<int, int>.
    int findTargetSumWays(vector<int>& nums, int target) {
        // instead of hardcoding an arbitrary number
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        totalSum = max(totalSum, (int) nums.size());   // special case when all numbers in nums are 0s
        vector<int> curr(2 * totalSum + 1);   // the range of the possible sum of nums
        int offset = totalSum;
        curr[nums[0] + offset] += 1;
        curr[-nums[0] + offset] += 1;
        // special case handling
        // When totalSum is even, all possible sums are even. Likewise for odd.
        // When (totalSum + target) is odd, one of even and the other is odd, there is no way to arrive
        // at the target.
        if ((totalSum + target) % 2) return 0;
        for (int i = 1; i < nums.size(); i++) {
            vector<int> next(curr.size());
            for (int j = 0; j < curr.size(); j++) {
                if (curr[j] == 0) continue;
                next[j + nums[i]] += curr[j];
                next[j - nums[i]] += curr[j];
            }
            curr = next;
        }
        return (abs(target) > totalSum) ? 0 : curr[target + offset];
        // unordered_map<int, int> curr({{nums[0], 1}, {-nums[0], 1}});
        // if (nums[0] == 0) curr[nums[0]]++;
        // for (int i = 1; i < nums.size(); i++) {
        //     unordered_map<int, int> next;
        //     for (auto kv : curr) {
        //         next[kv.first + nums[i]] += kv.second;
        //         next[kv.first - nums[i]] += kv.second;            }
        //     curr.swap(next);
        // }
        // return curr[target];
    }
};
