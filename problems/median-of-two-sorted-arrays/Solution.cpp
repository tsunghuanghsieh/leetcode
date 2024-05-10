#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Sum of the 2 positions in their respective sorted arrays will be the position of the medium of the final array.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        double res = 0.0;
        int s1 = nums1.size(), s2 = nums2.size(), idx_target = (s1 + s2) / 2;
        int start = 0, end = s1;
        // idx is the middle index in the array
        // right or r is the idx
        // left or l is the index immediate to the left of r
        int idx1, idx2, l1, r1, l2, r2;
        bool isOdd = (s1 + s2) % 2;

        // when start == end, the iteration will update l1, l2, r1, r2 to reflect final value.
        while (start <= end) {
            idx1 = (start + end) / 2;
            // when idx1 moves, idx2 will move in opposite direction. sum will remain unchanged.
            idx2 = idx_target - idx1;
            // setting to a default value at the out-of-boundary cases, idx? - 1 when index = 0 or
            // idx? when index = the size of array. this will eliminate boundary condition checks later
            // in if/else and return stmts and simplify the code.
            l1 = (idx1 == 0) ? INT_MIN : nums1[idx1 - 1];
            r1 = (idx1 == s1) ? INT_MAX : nums1[idx1];
            l2 = (idx2 == 0) ? INT_MIN : nums2[idx2 - 1];
            r2 = (idx2 == s2) ? INT_MAX : nums2[idx2];
            if (r1 < l2) {
                start = idx1 + 1;
            }
            else if (l1 > r2) {
                end = idx1;
            }
            else {
                break;
            }
        }
        return (isOdd) ? min(r1, r2) :
            // when even number, it will be the average of the middle 2 elements of the 4,
            // i.e., max of left and min of right.
            (max(l1, l2) + min(r1, r2)) / 2.0;
    }
};
