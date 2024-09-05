#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    // This implementaion coincides with LC Editorial soln 5.
    // It uses a stack to keep track of heights observed in increasing order.
    // When a lower height is observed, it pops all larger or equal heights off the stack,
    // calculates the size of rectangle, then push itself onto the stack.
    // After all heights are processed, it processes the stack to calculate the size of
    // rectangle.
    int largestRectangleArea(vector<int>& heights) {
        int larea = 0;
        stack<int> lows;
        for (int i = 0; i < heights.size(); i++) {
            while (!lows.empty() && heights[lows.top()] >= heights[i]) {
                int height = heights[lows.top()];
                lows.pop();
                int pos = (!lows.empty()) ? lows.top() + 1 : 0;
                larea = max(larea, height * (i - pos));
            }
            lows.push(i);
        }
        // Saw it in LC sample code. A simple change of appending 0 to heights will eliminate
        // the need of a repeated while loop below.
        while (!lows.empty()) {
            int height = heights[lows.top()];
            if (height == 0) break;
            lows.pop();
            int pos = (!lows.empty()) ? lows.top() + 1 : 0;
            larea = max(larea, height * ((int)heights.size() - pos));
        }
        return larea;
    }
};
