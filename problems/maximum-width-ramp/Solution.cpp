#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // Use map to store the number in vector as key and its indices as value. Enumerate through the map
    // backward to find the maximum width of the ramp (see README.md for definition).
    int maxWidthRamp(vector<int>& nums) {
        map<int, vector<int>> nummap;
        int lastidx = -1, maxWidth = 0;

        for (int i = 0; i < nums.size(); i++) {
            nummap[nums[i]].emplace_back(i);
        }
        for (auto itr = nummap.rbegin(); itr != nummap.rend(); itr++) {
            lastidx = max(lastidx, (*itr).second.back());
            if ((*itr).second.front() <= lastidx) maxWidth = max(maxWidth, lastidx - (*itr).second.front());
        }

        return maxWidth;
    }
};
