#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // This implementation resembles LC soln 2 and has O(n) runtime and space complexity.
    //
    // The solution I came up with second time around is to use stack<int> to store
    // max height and decreasing heights observed thereafter traversing left to right.
    // When a taller height is then encountered, it will compare against the top of stack
    // to determine water trapped, pop the top of stack off when it is taller and repeat
    // until it is shorter than the top of stack or the stack is empty before pushing
    // the taller height onto the stack. This approach resembles LC soln 3 and has O(n)
    // runtime and space complexity like LC soln 2.
    //
    // LC soln 4 has O(n) runtime complexity and O(1) space complexity. It uses 2 pointers
    // to keep track of left max and right max height respectively, traversing from both ends
    // towards the middle (when left max is taller, traverse from right to middle; right max
    // is taller, left to middle) and calculate water trapped along the way.
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
