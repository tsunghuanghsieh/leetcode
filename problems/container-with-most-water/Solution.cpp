#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // The idea is to start from the 2 ends and traverse inward. Since the amount of water is constrained
    // by the lower end, we move the lower end inward and then determine the new lower end. This process
    // repeats until the 2 ends meet. This is also LC Editorial soln 2.
    int maxArea(vector<int>& height) {
        int maxa = 0;

        for (int left = 0, right = height.size() - 1; left < right; (height[left] >= height[right]) ? right-- : left++) {
            maxa = max(maxa, min(height[left], height[right]) * (right - left));
        }
        return maxa;
    }
};
