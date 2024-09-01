#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa = 0;

        for (int left = 0, right = height.size() - 1; left < right; (height[left] >= height[right]) ? right-- : left++) {
            maxa = max(maxa, min(height[left], height[right]) * (right - left));
        }
        return maxa;
    }
};
