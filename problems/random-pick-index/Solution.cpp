#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    inline static string ClassName = "Solution";
    inline static string FuncName = "pick";

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (data.find(nums[i]) == data.end()) data[nums[i]] = vector<int>({i});
            else {
                data[nums[i]].emplace_back(i);
            }
        }
    }

    int pick(int target) {
        int n = data[target].size();
        return data[target][rand() % n];
    }
private:
    unordered_map<int, vector<int>> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
