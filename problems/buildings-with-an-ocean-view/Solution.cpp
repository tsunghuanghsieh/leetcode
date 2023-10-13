#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result = {int(heights.size() - 1)};
        int max_height = heights[heights.size() - 1];
        for (int idx = heights.size() - 2; idx >= 0; idx--) {
            if (heights[idx] > max_height) {
                max_height = heights[idx];
                result.push_back(idx);
            }
        }
        for (int i = 0; i < result.size() / 2; i++) {
            int temp = result[i];
            result[i] = result[result.size() - 1 - i];
            result[result.size() - 1 - i] = temp;
        }
        return result;
    }
};
