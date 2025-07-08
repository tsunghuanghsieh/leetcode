#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (auto itr = freq.begin(); itr != freq.end();) {
            for (int j = 0, first = itr->first; j < k; j++) {
                freq[first + j]--;
                // if the value is < 0, or the subsequent k numbers don't exist, no consecutive sequence
                if (freq[first + j] < 0 || (j + 1 < k && freq.count(first + j + 1) == 0)) return false;
            }
            while (itr != freq.end() && itr->second == 0) itr++;
        }
        return true;
    }
};
