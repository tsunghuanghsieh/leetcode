#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        set<vector<int>> setResults;

        if (nums.size() == 3) {
            if (nums[0] + nums[1] + nums[2] == 0) results.emplace_back(nums);
            return results;
        }

        sort(nums.begin(), nums.end());
        // use map to store the last index of the same value
        // this allows us to ensure the 3rd number is not the first or second
        map<int, int> mapNums;
        for (int i = 0; i < nums.size(); i++) {
            mapNums[nums[i]] = i;
        }

        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (mapNums.find(0 - nums[i] - nums[j]) != mapNums.end() &&
                    mapNums[0 - nums[i] - nums[j]] != i &&
                    mapNums[0 - nums[i] - nums[j]] != j) {
                    vector<int> triplet = {nums[i], nums[j], 0 - nums[i] - nums[j]};
                    sort(triplet.begin(), triplet.end());
                    // can't use std::find() since it is essentially O(n^3) runtime complexity
                    if (setResults.find(triplet) == setResults.end()) {
                        results.emplace_back(triplet);
                    }
                    setResults.insert(triplet);
                }
            }
        }
        return results;
    }
};