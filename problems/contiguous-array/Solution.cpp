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
    // Array implementation is LC soln 2.
    // unordered_map implementaion is LC soln 3.
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
