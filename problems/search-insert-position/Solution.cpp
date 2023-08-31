#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        // special cases
        if (nums[0] >= target) return 0;
        if (length == 1 || nums[length - 1] < target) return length;

        int pos, half;
        pos = half = length / 2;
        while (half >= 1) {
            half /= 2;
            if (nums[pos] >= target) {
                if (half == 0) {
                    pos--;
                    break; // return pos;
                }
                if (half) pos -= half;
            }
            else {
                if (half == 0) {
                    pos++;
                    break; // return pos;
                }
                if (half) pos += half;
            }
        }
        if (nums[pos] < target) pos++;
        return pos;
    }
};