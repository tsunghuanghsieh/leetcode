#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (k == 1) return 0;
        int res = INT_MAX;
        for (int i = k; i <= nums.size(); i++) {
            int diff = nums[i - 1] - nums[i - k];
            res = (res > diff) ? diff : res;
        }
        return res;
    }
};
