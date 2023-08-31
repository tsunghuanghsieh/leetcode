#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // special cases
        if (nums[0] >= target) return 0;
        if (nums.size() == 1 || nums[nums.size() - 1] < target) return nums.size();

        int low = 1, high = nums.size();
        while (low <= high) {
            // NOTE: if low + high causes buffer overflow before doing division, we can do low + (diff of high - low) / 2.
            int half = (low + high) / 2;
            if (nums[half] == target) {
                return half;
            }
            else if (nums[half] > target) {
                high = half - 1;
            }
            else {
                low = half + 1;
            }
        }
        return low;
    }
};