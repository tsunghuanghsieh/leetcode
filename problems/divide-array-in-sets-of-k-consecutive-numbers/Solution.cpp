#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln #1: map Runtime O(nlogn + nk) Space O(n)
    // LC Editorial soln #2: map + queue Runtime O(nlogn + n) Space O(n)
    // LC Editorial soln #3: unordered_map Runtime O(n) Space O(n)
    //
    // My implementation matches LC Editorial soln #1. It uses map<int, int> to store the value of the
    // number as key and the count of occurrence as the corresponding value. It iterates through the
    // map to decrement the count one (1) at a time to determine if the array can be divided into sets
    // of k consecutive numbers.
    //
    // Runtime complexity: O(nlogn + nk) or O(nlogn) for large n, small k or O(nk) for large k, small n
    // Space complexity O(n)
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
