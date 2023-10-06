#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // tracing backward
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;

        vector<bool> reachable(nums.size(), false);
        reachable[nums.size() - 1] = true;
        int idx = nums.size() - 2;
        reachable[idx] = idx + nums[idx] >= nums.size() - 1;
        idx--;

        while (idx >= 0) {
            int i = idx, stop = min<int>(nums.size() - 1, idx + nums[idx]);
            while (!reachable[i] && i <= stop) i++;
            if (i < stop || (i == stop && reachable[i])) reachable[idx] = true;
            idx--;
        }
        return reachable[0];
    }
};
