#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution2 {
public:
    // This approach traverse through the array backward while
    // keeping track of descending values as J (middle value) seen with a stack.
    // Once a larger value of J is encountered, pop all smaller values off the stack before
    // pushing it to the stack. The last value off the stack is the largest K (third value).
    // Return true when largest K is larger than the current value at index idx.
    bool find132pattern(vector<int>& nums) {
        stack<int> seenJ;
        int largestK = INT_MIN;
        for (int idx = nums.size() - 1; idx >= 0; idx--) {
            if (largestK > nums[idx]) return true;
            while (!seenJ.empty() && nums[idx] > seenJ.top()) {
                largestK = seenJ.top();
                seenJ.pop();
            }
            seenJ.push(nums[idx]);
        }
        return false;
    }
};
