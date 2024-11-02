#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    // LC soln 3, two pointers approach, enumerates backward through nums to identify, at each index,
    // the largest number encountered so far and stores them in a separate vector. It uses 2 pointers
    // to compare the number at each index in nums against the largest number in the separate vector
    // from the beginning. If the number in nums is larger, advance its pointer. If the number in the
    // separate vector is larger, compute the width and advance its pointer. Repeat until the end of
    // the separate vector is reached.
    //
    // LC soln 4, monotonic stack approach, enumerates nums once to store the index of the new lowest
    // low encountered in a stack. It enumerates nums vector backward and compares each num against the
    // value in nums of the index at the top of stack. If the num is larger and the stack is not empty,
    // compute the width and pop the stack until the value in nums of the index at the top of the stack
    // is larger than the num or the stack is empty. If the number in num is smaller, advance to the
    // next index in nums until it is no longer true or at the index 0 of nums.
    //
    // This approach is similar to LC soln 3 and soln 4.
    // Instead of identify and store the current largest number from the right in a separate vector
    // (soln 3) and store the new lowest lows (to the left of the current index) in a stack (soln 4),
    // as well as enumerate the length of nums the second time (both 3 and 4), it stores the index of
    // the new lowest lows (from left to right) the new highest high (from right to left) in vectors,
    // and compares between the 2 vectors to compute the width (additional details below).
    //
    // From left to right, I need to keep track of the new lowest encountered. On the other hand,
    // from right to left, I need to keep track of the new highest encountered. With those, I start
    // with the largest low (smallest index) and find the width against the largest high (smallest
    // index) until the high is less than the low or is the smallest high. If it is the smallest low,
    // I am done. If not, increment the low and continue with the current high.
    //
    // Also tried dynamic programming, it is in fact a brute force attempt. Even with memoization,
    // it results in TLE.
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
