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
        unordered_set<int> us_nums(nums.begin(), nums.end());

        for (int num : us_nums) {
            if (!us_nums.count(num - 1)) {
                int key = num;
                while (us_nums.count(num)) num++;
                count = max(count, num - key);
            }
        }
        return count;
    }
};
