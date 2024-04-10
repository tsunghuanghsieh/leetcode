#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mnums;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            mnums[nums[i]]++;
        }
        // for (auto itr = mnums.begin(); itr != mnums.end(); itr++) {
        //     if (itr->second == 1) return -1;
        //     int quotient = itr->second / 3, rem = itr->second % 3;
        //     if (quotient == 0) count++;
        //     else if (rem == 0) count += quotient;
        //     else count += ++quotient;
        // }
        //
        // LC Editorial soultion is able to condense if/else stmts into 1 single line.
        //
        for (auto [_, num] : mnums) {
            if (num == 1) return -1;
            count += ceil((double)num / 3);
        }
        return count;
    }
};
