#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // special case
        if (nums.size() == 1) return 0;

        // general cases
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            // when nums[mid] > nums[mid + 1], mid is in a localized descending slope.
            // peak is smaller (to the left), discard right side and move right to mid.
            // conversely, move left to (mid + 1), the larger one.
            // when left == right, it arrives at a local peak.
            if (nums[mid] > nums[mid + 1]) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};
