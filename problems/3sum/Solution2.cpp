#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <vector>

using namespace std;

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int left = i + 1, right = nums.size() - 1; left < right;) {
                int target = -(nums[left] + nums[right]);
                if (nums[i] == target) {
                    if (left == i + 1 || right == nums.size() - 1 || (nums[right] != nums[right + 1] && nums[left] != nums[left - 1])) {
                        results.push_back({nums[i], nums[left], nums[right]});
                    }
                    right--;
                    left++;
                }
                else if (nums[i] > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return results;
    }
};