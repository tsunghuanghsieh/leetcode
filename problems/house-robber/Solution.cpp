#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Initial idea was to solve it using DP. However, a pattern emerged while traversing through nums.
    // I just need to keep track of the max sum from the beginning of nums to the current index. At each
    // index, max sum is the max of the sum of index i and i - 2, and the sum at index i - 1. When done,
    // the max amount is stored in index nums.size() - 1.
    //
    // Runtime complexity is O(n) and space complexity is O(1)
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        }
        return nums[nums.size() - 1];
    }
};
