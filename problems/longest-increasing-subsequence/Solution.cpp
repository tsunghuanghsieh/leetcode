#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // LC soln #1 initializes a distance vector of size nums to 1, iterates through nums.
    // At each index, it iterates again from index 0 to the previous index, ignoring values
    // larger than that of the current index, finding the largest distance among the indices
    // of smaller value, and increment the largest distance by 1 for the current index. Return
    // the largest value in the distance vector. Time complexity is O(n^2) and space complexity
    // is O(n).
    //
    // LC soln #2 iterates through nums and builds an increasing vector. If the number is
    // larger, appends to the end of vector. Else, iterate through the increasing vector,
    // and replace the first larger number in the vector. The size of the increasing vector
    // is the length of the longest increasing sequence. Time complexity is O(n^2) and space
    // complexity is O(n).
    //
    // LC soln #3 is same as soln #2, using binary search instead of linear search in the
    // increasing vector. Time complexity is O(nlogn) and space complexity is O(n).
    //
    // The worst case scenario, runtime complexity is O(n^2) and space complexity is O(n).
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> order;
        int longest = 1;

        // runtime complexity: O(n)
        for (int i = nums.size() - 1; i >= 0; i--) {
            auto itr = order.upper_bound(nums[i]);   // find the first element > nums[i]
            if (itr == order.end()) order[nums[i]] = 1;
            else {
                int distance = 0;
                // find the longest increasing subsequence among elements sesen so far > nums[i]
                // the worst case: runtime complexity: O(n)
                for (; itr != order.end(); itr++) {
                    distance = max(distance, itr->second + 1);
                }
                order[nums[i]] = distance;
                // find the longest increasing subsequence among elements seen so far
                longest = max(longest, distance);
            }
        }
        return longest;
    }
};
