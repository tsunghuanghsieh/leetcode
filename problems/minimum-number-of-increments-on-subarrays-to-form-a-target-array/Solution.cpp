#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // This problem is similar to
    // [Largest Rectangle In Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
    // See https://github.com/tsunghuanghsieh/leetcode/problems/largest-rectangle-in-histogram/ for
    // implementation.
    // The approach is to find local peaks, when currnent number is smaller than the previous number,
    // current number is the bottom of a local subarray. At the end of target, peak is the remaining
    // number of increments required.
    //
    // The other approach found online is to calculate, at each iteration, the min increment if the
    // current number is larger than the previous number. If the current number is less than the
    // previous number, do nothing. This approach is simpler than my approach.
    int minNumberOperations(vector<int>& target) {
        int res = 0, peak = target[0];

        for (int i = 1; i < target.size(); i++) {
            if (target[i] == peak) continue;
            if (target[i] < peak) res += peak - target[i];   // add minimum increment of a local peak
            peak = target[i];   // update current peak
        }
        return res += peak;

        // Approach found online
        // int res = target[0];
        // for (int i = 1; i < target.size(); i++) {
        //     // add required minimum increment since the previous number
        //     if (target[i] > target[i - 1]) res += target[i] - target[i - 1];
        // }
        // return res;
    }
};
