#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution1 {
public:
    // This is the same as LC soln #3, using multiset<int>,
    // instead of priority_queue<int> (LC soln #2).
    //
    // The key is to separate k numbers in 2 separate max and min heap. Depending on
    // k, even or odd, the median is the average of the top of max and min heap, and
    // the top of max heap, respectively.
    //
    // multiset runs slower and has higher memory usage than priority_queue.
    //
    // Runtime complexity: O(nlogk)
    // Space complexity: O(k)
    //
    // Below shows the states at each step. Given this, the logic is obvious.
    //
    //  k is odd                            k is even
    //
    //  lte   gte         lte   gte         lte   gte         lte   gte
    //   x     x           x     x           x     x           x     x
    //   x     x           x     x           x     x           x     x
    //   x                 x
    //  remove from lte   remove from gte   remove from lte   remove from gte
    //  lte   gte         lte   gte         lte   gte         lte   gte
    //   x     x           x     x           x     x           x     x
    //   x     x           x                       x           x
    //                     x
    //  insert new val    insert new val    insert new val    insert new val
    //  lte   gte         lte   gte         lte   gte         lte   gte
    //   x     x           x     x           x     x           x     x
    //   x     x           x                 n     x           x
    //   n                 x                                   n
    //                     n
    //  rebalance         rebalance         rebalance         rebalance
    //  lte   gte         lte   gte         lte   gte         lte   gte
    //     <->               -->               <->               -->
    //   x     x           x     x           x     x           x     x
    //   x     x           x     x           x     x           x     x
    //   x                 x
    //  --> once since the largest in lte belongs to gte half.
    //  <-> back and forth is required to ensure the largest in lte will be smaller than
    //  the smallest in gte.
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> lte, gte;   // largest -> smallest

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                // remove the oldest element in k sliding window
                if (lte.find(nums[i - k]) != lte.end()) lte.erase(lte.find(nums[i - k]));
                else gte.erase(gte.find(nums[i - k]));
            }
            lte.insert(nums[i]);
            // move the largest in lte to the smallest of gte
            gte.insert(*lte.rbegin());
            lte.erase(prev(lte.end()));
            // either lte == gte or lte == gte + 1, otherwise rebalance
            if (lte.size() < gte.size()) {
                lte.insert(*gte.begin());
                gte.erase(gte.begin());
            }
            if (i >= k - 1) {
                if (k & 1) res.emplace_back(*lte.rbegin());
                else res.emplace_back(((double)*lte.rbegin() + (double)*gte.begin()) / 2.0);
            }
        }
        return res;
    }
};
