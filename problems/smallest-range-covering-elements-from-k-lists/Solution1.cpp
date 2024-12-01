#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution1 {
public:
    // LC soln #3 2-pointer (sliding window)
    // Sort all numbers in all vectors in nums and use 2 pointers to indicate the range that includes at
    // least one number from all vectors in nums. Keep traversing right until a number from all vectors
    // has been encountered and then traverse the left pointer to find the minimum range until one vector
    // is missing from the range.
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res(2);
        vector<pair<int, int>> nums_order;
        for (int k = 0; k < nums.size(); k++) {
            for (int i = 0; i < nums[k].size(); i++) {
                nums_order.emplace_back(pair<int, int>{nums[k][i], k});
            }
        }
        sort(nums_order.begin(), nums_order.end());
        vector<int> seen(nums.size());
        int curr_range = INT_MAX;
        for (int left = 0, right = 0, cnt = 0, k = nums.size(); right < nums_order.size(); right++) {
            if (seen[nums_order[right].second]++ == 0) cnt++;
            if (cnt < k) continue;
            while (cnt == k) {
                if (curr_range > nums_order[right].first - nums_order[left].first) {
                    curr_range = nums_order[right].first - nums_order[left].first;
                    res.assign({nums_order[left].first, nums_order[right].first});
                }
                if (--seen[nums_order[left].second] == 0) cnt--;
                left++;
            }
        }
        return res;
    }
};
