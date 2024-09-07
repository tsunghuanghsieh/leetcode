#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // The approach is enumerate through nums once to identify and store unique individual numbers in
    // unordered_set for constant (on average) find, insert, delete ops. We then enumerate through the
    // unordered_set, identify and delete consecutive numbers, and store the starting number (key) and
    // count (value) in unordered_map. Finally, we enumerate through the unordered_map to link up
    // consecutive sequences to find the longest consecutive sequence.
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        unordered_set<int> us_nums, visited, um_visited;
        unordered_map<int, int> um_nums;

        for (int num : nums) us_nums.insert(num);
        for (int num : us_nums) {
            int key = num;
            while (visited.find(num) == visited.end() && us_nums.find(num) != us_nums.end()) {
                visited.insert(num);
                um_nums[key] = num - key + 1;
                num++;
            }
        }
        for (auto [key, value] : um_nums) {
            int temp_k = key, temp_v = value;
            while (um_visited.find(temp_k) == um_visited.end() && um_nums.find(temp_k + temp_v) != um_nums.end()) {
                um_visited.insert(temp_k);
                temp_k += temp_v;
                temp_v = um_nums[temp_k];
            }
            um_nums[key] = temp_k + temp_v - key;
            count = max(count, temp_k + temp_v - key);
        }
        return count;
    }
};
