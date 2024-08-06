#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // unordered_map implementation
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int maxL = 0;
        stack<int> odd, even;
        unordered_map<int, int> ranges;
        if (nums[0] == 0) even.push(0);
        else odd.push(0);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                even.push(i);
                if (odd.size() > 0) {
                    int key = odd.top() - 1, start = odd.top();
                    if (ranges.count(key) > 0) {
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
                    if (ranges.count(key) > 0) {
                        start = ranges[key];
                    }
                    ranges[i] = start;
                    even.pop();
                }
            }
            if (ranges.count(i)) {
                maxL = max(maxL, i - ranges[i] + 1);
            }
        }
        return maxL;
    }
};
