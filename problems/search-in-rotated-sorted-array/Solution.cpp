#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int fidx = -1;

        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;

            if (nums[mid] == target) return mid;
            if (mid == left) return (nums[mid] == target) ? mid : (nums[right] == target) ? right : fidx;
            if ((nums[left] < nums[mid] && nums[left] <= target && target <= nums[mid]) ||
                (nums[left] > nums[mid] && (nums[left] <= target || target <= nums[mid]))) {
                right = mid;
            }
            else if ((nums[mid] < nums[right] && nums[mid] <= target && target <= nums[right]) ||
                     (nums[mid] > nums[right] && (nums[mid] <= target || target <= nums[right]))) {
                left = mid;
            }
            else {
                return fidx;
            }
        }
        return (nums[0] == target) ? 0 : fidx;
    }
};