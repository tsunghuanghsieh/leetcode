#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> mapNums;
        for (int i = 0; i < nums.size(); i++) {
            mapNums[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (mapNums.find(diff) != mapNums.end() && mapNums[diff] != i) {
                result.push_back(i);
                result.push_back(mapNums[diff]);
                break;
            }
        }
        return result;
    }
};