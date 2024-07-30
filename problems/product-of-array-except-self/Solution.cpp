#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // LC solution
    // |right ->         |||left <-
    // | 2| 3| 4|  5|   7|||   2|   3|  4| 5| 7|
    // | 1| 2| 6| 24| 120||| 420| 140| 35| 7| 1|
    //
    // My scratch book
    // |right ->         |||left <-
    // | 2| 3|  4|   5| 7||| 2|   3|   4|  5| 7|
    // | 2| 6| 24| 120| -||| -| 420| 140| 35| 7|
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());

        // going right
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        // going left
        for (int i = nums.size() - 2, prod = 1; i >= 0; i--) {
            prod *= nums[i + 1];
            res[i] *= prod;
        }

        return res;
    }
};
