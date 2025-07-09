#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC Editorial soln #1: map Runtime O(nlogn + nk) Space O(n)
    // LC Editorial soln #2: map + queue Runtime O(nlogn + n) Space O(n)
    // LC Editorial soln #3: unordered_map Runtime O(n) Space O(n)
    //
    // This implementation is similar to LC Editorial soln #2, except that, instead of using
    // map<int, int> like Solution.cpp (soln #1), nums is sorted. As the result, it takes less
    // time to execute all LC test cases when runtime complexity is the same as soln #2.
    //
    // This can also be implemented using vector<int> using 2 pointers, instead of deque<int>.
    //
    // Runtime complexity: O(nlogn + n) or O(nlogn) for large n
    // Space complexity O(k)
    bool isPossibleDivide(vector<int>& nums, int k) {
        int height = 0;   // required height at num[i]
        deque<int> cntAdded(k, 0);   // sliding window for height of the previous k numbers
        sort(nums.begin(), nums.end());
        for (int i = 0, prevValue = 0; i < nums.size();) {
            int currHeight = 1;
            height -= cntAdded.front();   // subtracting height of completed sequences
            cntAdded.pop_front();
            // check for consecutive numbers
            if (prevValue != 0 && prevValue + 1 != nums[i] && height) return false;
            // get count (height) for the current number
            while (i + currHeight < nums.size() && nums[i] == nums[i + currHeight]) currHeight++;
            // required height > current height
            if (height > currHeight) return false;
            cntAdded.push_back(currHeight - height);
            height = currHeight;
            prevValue = nums[i];
            i += currHeight;
        }
        // after for, if the array is divisible, height should == cndAdded.front()
        if (height != cntAdded.front()) return false;
        return true;
    }
};
