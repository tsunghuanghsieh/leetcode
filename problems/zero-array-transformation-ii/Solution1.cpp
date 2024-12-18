#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(nums.size() + 1);
        int k = 0, diff = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (diff + prefix[i] < nums[i]) {
                if (k == queries.size()) return -1;
                int l = queries[k][0], r = queries[k][1], val = queries[k][2];
                k++;
                if (r < i) continue;
                prefix[max(l, i)] += val;
                prefix[r + 1] -= val;
            }
            diff += prefix[i];
        }
        return k;
    }
};
