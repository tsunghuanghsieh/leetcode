#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    // Runtime and space complexity is O(n)
    // The initial approach was to use unordered_map to store starting (value) and ending (key) index
    // containing the same number of 0s and 1s. However, unordered_map takes more time to execute the
    // same opearations than plain old array. With unordered_map, O(n) will be the worst case space
    // complexity, average case will be better.
    // Array implementation is similar to LC soln 2.
    // unordered_map implementaion is similar to LC soln 3.
    //
    // LC soln approach
    // The approach is more intuitive and simpler. It just needs to keep track of the index of the first
    // encounter for distinct counts. The lengths is then calculated by (current index - the index of the
    // first encounter).
    //
    // When the same count are encountered more than once, the number of 0s and 1s are equal between
    // the indices, e.g., count == 1, the number is 6 (7 - 1), count == 2, the number is 4 (10 - 6).
    //     [1,0,0,1,1,1,0,1,1,0]
    //    0 1 2 3 4 5 6 7 8 9 10
    //  3| | | | | | | | | |*| |
    //  2| | | | | | |*| |*| |*|
    //  1| |*| | | |*| |*| | | |
    //  0|*| |*| |*| | | | | | |
    // -1| | | |*| | | | | | | |
    //
    // My approach is to use stacks to keep track of every pair of 0s and 1s encountered, and use ranges
    // to store the lengths.
    //  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]
    //   0  1  2  3  4  5  6  7  8  9  <-- start | key
    //   1  4  3        6  7     9     <-- end   | value
    // Each end index marks a pair of 0s and 1s. If the start, 5, immediate after end, 4, has an end, 6,
    // they can be joined to form a longer length.
    //
    // Transpose key and value makes finding connected lengths easier.
    //  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]
    //   0  1  2  3  4  5  6  7  8  9  <-- end   | key
    //      0     2  1     5  6     8  <-- start | value
    //
    //   0  1  2  3  4  5  6  7  8  9  <-- end   | key
    //      0     0  1     1  6     6  <-- start connected
    //
    // i 0                             i 1                             i 2
    //  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]
    //   0  1  2  3  4  5  6  7  8  9    0  1  2  3  4  5  6  7  8  9    0  1  2  3  4  5  6  7  8  9  key
    //  -1                              -1  0                           -1  0 -1                       value
    // stack 0:                        stack 0: 1                       stack 0: 1 2
    // stack 1: 0                      stack 1:                         stack 1:
    //
    // i 3                             i 4                             i 5
    //  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]
    //   0  1  2  3  4  5  6  7  8  9    0  1  2  3  4  5  6  7  8  9    0  1  2  3  4  5  6  7  8  9  key
    //  -1  0 -1  0                     -1  0 -1  0  1                  -1  0 -1  0  1 -1              value
    // stack 0: 1                      stack 0:                         stack 0:
    // stack 1: 3                      stack 1: 3 4                     stack 1: 3 4 5
    //
    // i 6                             i 7                             i 8
    //  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]
    //   0  1  2  3  4  5  6  7  8  9    0  1  2  3  4  5  6  7  8  9    0  1  2  3  4  5  6  7  8  9  key
    //  -1  0 -1  0  1 -1  1            -1  0 -1  0  1 -1  1  6         -1  0 -1  0  1 -1  1  6 -1     value
    // stack 0: 6                      stack 0:                         stack 0:
    // stack 1: 3 4                    stack 1: 3 4 7                   stack 1: 3 4 7 8
    //
    // i 9
    //  [1, 0, 0, 1, 1, 1, 0, 1, 1, 0]
    //   0  1  2  3  4  5  6  7  8  9
    //  -1  0 -1  0  1 -1  1  6 -1  6
    // stack 0: 9
    // stack 1: 3 4 7
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int maxL = 0;
        stack<int> odd, even;
        int ranges[nums.size()];
        if (nums[0] == 0) even.push(0);
        else odd.push(0);
        ranges[0] = -1;
        for (int i = 1; i < nums.size(); i++) {
            ranges[i] = -1;
            if (nums[i] == 0) {
                even.push(i);
                if (odd.size() > 0) {
                    int key = odd.top() - 1, start = odd.top();
                    if (key >= 0 && ranges[key] != -1) {
                        start = ranges[key];
                    }
                    ranges[i] = start;
                    odd.pop();
                }
            }
            else {
                odd.push(i);
                if (even.size() > 0) {
                    int key = even.top() - 1, start = even.top();
                    if (key >= 0 && ranges[key] != -1) {
                        start = ranges[key];
                    }
                    ranges[i] = start;
                    even.pop();
                }
            }
            if (ranges[i] >= 0) {
                maxL = max(maxL, i - ranges[i] + 1);
            }
        }
        return maxL;
    }
};
