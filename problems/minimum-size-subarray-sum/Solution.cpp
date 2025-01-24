#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Sliding window
    // Runtime complexity is O(nums.size()) and space complexity is O(1).
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX, sum = 0;
        for (int start = 0, end = 0; end < nums.size(); end++) {
            sum += nums[end];
            if (sum >= target) {
                if (start == end) return 1;
                while (sum >= target) {
                    len = min(len, end - start + 1);
                    sum -= nums[start++];
                }
            }
        }
        return (len == INT_MAX) ? 0 : len;
    }
};
