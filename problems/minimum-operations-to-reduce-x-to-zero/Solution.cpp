#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int lsum = 0, rsum = 0, minops = INT_MAX;
        stack<int> sxm;

        // store the running sum of the array from left to right in a stack and update min ops accordingly.
        for (int i = 0; i <= nums.size() - 1; i++) {
            lsum += nums[i];
            if (lsum > x) break;
            if (lsum == x) minops = min<int>(minops, i + 1);
            sxm.push(lsum);
        }
        // get the running sum of the array from right to left and compare the total running sums to x.
        for (int i = nums.size() - 1; i >= 0; i--) {
            rsum += nums[i];
            if (rsum > x) break;
            if (rsum == x) {
                return min<int>(minops, nums.size() - i);
            }
            while (!sxm.empty() && rsum + sxm.top() > x) {
                sxm.pop();
            }
            if (!sxm.empty() && rsum + sxm.top() == x) {
                if (sxm.size() >= i) break;
                minops = min<int>(minops, sxm.size() + nums.size() - i);
            }
        }
        return (minops == INT_MAX) ? -1 : minops;
    }
};