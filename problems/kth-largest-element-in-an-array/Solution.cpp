#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> mnums;
        int res;

        for (int i = 0; i < nums.size(); i++) {
            // map insert runtime: ~log(map_size)
            mnums[nums[i]]++;
        }
        for (auto itr = mnums.rbegin(); itr != mnums.rend(); itr++) {
            k -= itr->second;
            if (k <= 0) {
                res = itr->first;
                break;
            }
        }
        return res;
    }
};
