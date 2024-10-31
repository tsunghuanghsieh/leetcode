#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // use unordered_map to store the index of the last occurrence of a number and a vector for
    // the sorted unique numbers in nums. run through unordered_map the second time to determine
    // the largest index among (the numbers >= the current number) and sort the vector. enumerate
    // nums to determine the largest width ramp.
    int maxWidthRamp(vector<int>& nums) {
        unordered_map<int, int> back;
        vector<int> sorted_nums;
        int lastidx, maxWidth = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (back.count(nums[i]) == 0) sorted_nums.emplace_back(nums[i]);
            back[nums[i]] = i;
        }
        sort(sorted_nums.begin(), sorted_nums.end(), greater<int>());
        lastidx = back[sorted_nums[0]];
        for (int i = 1; i < sorted_nums.size(); i++) {
            if (back[sorted_nums[i]] < lastidx) {
                back[sorted_nums[i]] = lastidx;
            }
            else {
                lastidx = back[sorted_nums[i]];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            maxWidth = max(maxWidth, back[nums[i]] - i);
        }
        return maxWidth;
    }
};
