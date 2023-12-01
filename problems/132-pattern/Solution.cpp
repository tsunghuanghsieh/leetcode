#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int, int> ranges;
        ranges[nums[0]] = nums[0];
        int curr_low = nums[0], curr_high = nums[0];

        for (int pos = 1; pos < nums.size(); pos++) {
            if (nums[pos] > curr_high) {
                ranges[curr_low] = curr_high = nums[pos];
                // excluding ranges that are >= the current high.
                map<int, int>::iterator itr_end = ranges.lower_bound(nums[pos]);
                // first range is the current low and high range, skip it.
                for (auto itr = ++ranges.begin(); itr != itr_end;) {
                    if (itr->first < nums[pos] && itr->second > nums[pos]) {
                        return true;
                    }
                    auto prev = itr++;
                    // Current range overlaps earlier range, deleting smaller range.
                    if (prev->second < curr_high) {
                        ranges.erase(prev->first);
                    }
                }
            }
            else if (nums[pos] < curr_high && nums[pos] > curr_low) {
                return true;
            }
            else if (nums[pos] < curr_low) {
                if (curr_low == curr_high) ranges.erase(curr_low);
                curr_low = curr_high = nums[pos];
                ranges.emplace(curr_low, curr_high);
            }
        }
        return false;
    }
};
