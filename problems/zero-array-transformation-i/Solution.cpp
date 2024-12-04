#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Online solution is to use 1 at l and -1 at r + 1 to indicate start and end of indices, li and ri.
    // Then traverse through the vector to calculate its prefix sum and compare against nums.
    //
    // My initial quick and dirty approach was to enumerate through all queries and count all decrements
    // at i-th index, then subtract it from nums. It encountered LTE error.
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(nums.size() + 1);
        for (const auto& query : queries) {
            prefix[query[0]]++;
            prefix[query[1] + 1]--;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (i > 0) prefix[i] += prefix[i - 1];
            if (nums[i] > prefix[i]) return false;
        }
        return true;
    }
};
