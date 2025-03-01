#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // The worst case scenario, runtime complexity is O(n^2) and space complexity is O(n).
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> order;
        int longest = 1;

        // runtime complexity: O(n)
        for (int i = nums.size() - 1; i >= 0; i--) {
            auto itr = order.upper_bound(nums[i]);   // find the first element > nums[i]
            if (itr == order.end()) order[nums[i]] = 1;
            else {
                int distance = 0;
                // find the longest increasing subsequence among elements sesen so far > nums[i]
                // the worst case: runtime complexity: O(n)
                for (; itr != order.end(); itr++) {
                    distance = max(distance, itr->second + 1);
                }
                order[nums[i]] = distance;
                // find the longest increasing subsequence among elements seen so far
                longest = max(longest, distance);
            }
        }
        return longest;
    }
};
