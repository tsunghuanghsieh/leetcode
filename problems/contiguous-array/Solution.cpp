#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
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
