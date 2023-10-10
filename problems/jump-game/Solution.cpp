#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // tracing backward
    bool canJump(vector<int>& nums) {
        int idx_reachable = nums.size() - 1, idx = nums.size() - 2;
        while (idx >= 0) {
            if (idx + nums[idx] >= idx_reachable) idx_reachable = idx;
            idx--;
        }
        return idx_reachable == 0;
    }
};
