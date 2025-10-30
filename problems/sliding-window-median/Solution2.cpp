#include <iostream>
#include <vector>

using namespace std;

#include "FenwickTree.cpp"

class Solution2 {
public:
    // Fenwick Tree (Binary Index Tree) based on user LC submissions
    // Runtime complexity: O(nlogk)
    // Space complexity: O(n)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int arrNums[nums.size()], arrSize = nums.size();
        memcpy(arrNums, nums.data(), arrSize * sizeof(int));
        sort(arrNums, arrNums + arrSize);
        // make arrNums unique and update arrSize to reflect that
        arrSize = unique(arrNums, arrNums + arrSize) - arrNums;
        FenwickTree<int> fenwick(arrSize);
        for (int i = 0; i < nums.size(); i++) {
            // determine the 0-based index in arrNums and set it (1-based index in Fenwick)
            nums[i] = lower_bound(arrNums, arrNums + arrSize, nums[i]) - arrNums + 1;
            fenwick.increment(nums[i]);
            if (i >= k) fenwick.decrement(nums[i - k]);
            if (i >= k - 1) {
                if (k & 1) {
                    res.emplace_back(arrNums[fenwick.getSumIndex((k + 1) / 2) - 1]);
                }
                else {
                    res.emplace_back(((long)arrNums[fenwick.getSumIndex(k / 2 + 1) - 1] +
                        (long)arrNums[fenwick.getSumIndex(k / 2) - 1]) / 2.0);
                }
            }
        }
        return res;
    }
};
