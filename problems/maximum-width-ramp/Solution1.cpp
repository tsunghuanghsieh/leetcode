#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    // From left to right, I need to keep track of the new lowest encountered. On the other hand,
    // from right to left, I need to keep track of the new highest encountered. With those, I start
    // with the largest low (smallest index) and find the width against the largest high (smallest
    // index) until the high is less than the low or is the smallest high. If it is the smallest low,
    // I am done. If not, increment the low and continue with the current high.
    //
    // Also tried dynamic programming, it is essentially an optimized brute force which results in TLE.
    int maxWidthRamp(vector<int>& nums) {
        vector<int> fromRight_max, fromLeft_min;
        int count = nums.size(), maxNum = INT_MIN, minNum = INT_MAX, maxWidth = 0;
        for (int i = 0 ; i < count; i++) {
            // find decreasing lows
            if (minNum > nums[i]) {
                minNum = nums[i];
                fromLeft_min.emplace_back(i);
            }
            // find increasing highs
            if (maxNum < nums[count - 1 - i]) {
                maxNum = nums[count - 1 - i];
                fromRight_max.emplace_back(count - i - 1);
            }
        }
        for (int l = 0, r = fromRight_max.size() - 1; l < fromLeft_min.size(); l++) {
            if (nums[fromLeft_min[l]] > nums[fromRight_max[r]]) continue;
            while (r >= 0 && nums[fromLeft_min[l]] <= nums[fromRight_max[r]]) {
                maxWidth = max(maxWidth, fromRight_max[r] - fromLeft_min[l]);
                r--;
            }
            if (r < 0 && maxWidth > 0) break;
        }
        return maxWidth;
    }
};
