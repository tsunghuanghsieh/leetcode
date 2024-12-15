#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // This is similar to https://leetcode.com/problems/zero-array-transformation-i, and we can use
    // prefix sum and compare against nums vector. However, we need to determine the least k elements,
    // if possible.  The naive approach results in TLE error. LC hint suggests using binary search.
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size() - 1, qsize = queries.size() - 1, zeros = 0;
        // handle special case when nums is all 0s
        for (int i = 0; i < nums.size(); i++) if (nums[i] == 0) zeros++;
        if (zeros == nums.size()) return 0;
        while (l <= r) {   // binary search
            int m = (l + r) / 2;
            vector<int> diff(nums.size() + 1);
            for (int q = 0; q <= m; q++) {   // find prefix sum
                diff[queries[q][0]] += queries[q][2];
                diff[queries[q][1] + 1] -= queries[q][2];
            }
            int i = 0;
            for (; i < nums.size(); i++) {   // compare prefix sum against nums
                if (i > 0) diff[i] += diff[i - 1];
                if (nums[i] > diff[i]) break;
            }
            if (i == nums.size()) {
                if (m == qsize) break;
                r = m - 1;
            }
            else {
                if (m == qsize) return -1;
                l = m + 1;
            }
        }
        return ++l;
    }
};
