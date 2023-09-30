#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;

        int left = 0, right = nums.size() - 1, mid;

        while (left < right) {
            // to avoid overflow when size of nums is big
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            }
            else { // nums[mid] < target
                left = mid + 1;
            }
        }

        //
        // Initial attemp:
        // Use linear search for the ending index.
        // This is easier to get right during interview.
        //
        // if (nums.size() > 0 && nums[left] == target) {
        //     result.push_back(left);
        //     int last = left;
        //     while(last + 1 < nums.size() && nums[last + 1] == target) last++;
        //     result.push_back(last);
        // }
        // else {
        //     result = {-1, -1};
        // }

        // Revised attempt:
        // Instead of linear search for the ending index, use binary search.
        // This is harder to get right during interview.
        if (nums.size() == 0 || nums[left] != target) return {-1, -1};
        result.push_back(left);
        left = 0, right = nums.size() - 1;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (mid == left) {
                if (nums[right] == target) left = right;
                break;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else { // nums[mid] <= target
                left = mid;
            }
        }
        result.push_back(left);

        return (nums.size() != 1) ? result : (nums[0] == target) ? vector<int>{0, 0} : result;
    }
};