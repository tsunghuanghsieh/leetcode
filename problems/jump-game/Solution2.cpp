#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    // tracing forward
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        for (int i = 0, idx = 0; i < nums.size() - 1; i++) {
            if (i + nums[i] > idx) idx = i + nums[i];
            if (idx == i) return false;
            if (idx >= nums.size() - 1) return true;
        }
        return true;
    }
};
