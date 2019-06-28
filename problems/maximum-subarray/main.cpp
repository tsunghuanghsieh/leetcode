#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // get the running sum and save in the current element
            // if the previous sum is less than 0
            // addin it will reduce the running sum
            // so start new running sum
            if (nums[i - 1] > 0) nums[i] += nums[i - 1];
        }
        for (int i = 1; i < nums.size(); i++) {
            largest = max(largest, nums[i]);
        }
        return largest;
    }
};

int main() {
    Solution s;
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    s.maxSubArray(nums);
    return 0;
}