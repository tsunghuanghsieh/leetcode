#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sums;
        int count = 0, sum = 0;
        sums[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // if subarray in the current sum equals to k, current sum - k must exist in sums.
            if (sums.count(sum - k) > 0) count += sums[sum - k];
            sums[sum]++;
        }
        return count;
    }
};
