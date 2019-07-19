#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int units = 0;
        int size = height.size();
        if (size <= 2) return units; // using int arrays instead of vector<int>, need array boundary check.
        // keep track of the highest elevation seen so far at current index going eastbound (to the left) and westbound (to the right)
        int eastBound[size - 1], westBound[size - 1];
        int leftMax = 0, rightMax = 0;
        for (int i = 1; i < size; i++) {
            leftMax = max(leftMax, height[i - 1]);
            eastBound[i - 1] = leftMax;
            rightMax = max(rightMax, height[size - i]);
            westBound[i - 1] = rightMax;
        }

        // enumerate through vector and find water trapped at current index
        // index 0 and height.size() - 1 will not be able to trap any water
        for (int i = 1; i < size; i++) {
            // height[i] is the highest elevation so far going either eastbound or westbound, so continue.
            if (eastBound[i - 1] <= height[i] || westBound[size - 1 - i] <= height[i]) continue;
            units += min(eastBound[i - 1], westBound[size - 1 - i]) - height[i];
        }
        return units;
    }
};

int main() {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> height = {0,1,2,3,4,5,6,7,8,8};
    // vector<int> height = {3,0,1,4};
    int units = s.trap(height);
    cout << "Water " << units << " trapped." << endl;
    return 0;
}