#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // traverse from end and stop when a smaller number is encountered
        // replace the smaller number with a smallest larger number from the digits seen during the traversal
        // then reorder the digits in ascending order
        int idx = nums.size() - 1;
        while (idx > 0 && nums[idx] <= nums[idx - 1]) idx--;

        int last = nums.size() - 1;
        int temp;
        if (idx > 0) {
            for (int i = 0; idx + i <= last; i++) {
                if (nums[idx - 1] < nums[last - i]) {
                    temp = nums[idx - 1];
                    nums[idx - 1] = nums[last - i];
                    nums[last - i] = temp;
                    break;
                }
            }
        }
        for (int i = 0; idx + i < last - i; i++) {
            temp = nums[idx + i];
            nums[idx + i] = nums[last - i];
            nums[last - i] = temp;
        }
    }
};