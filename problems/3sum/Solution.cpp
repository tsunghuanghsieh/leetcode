#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) { // first number
            unordered_set<int> seen;
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) { // second number
                // target is the 3rd number to  make the sum zero
                int target = -(nums[i] + nums[j]);
                if (seen.find(target) != seen.end()) {
                    // seen the 3rd number before
                    results.push_back({nums[i], target, nums[j]});
                    // look forward to eliminate duplicate triplets
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                }
                seen.insert(nums[j]);
            }
        }
        return results;
    }
};