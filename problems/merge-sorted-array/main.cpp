#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = nums1.size() - 1;
        m--;
        n--;

        // special case where nums1 is empty
        // straight copy from nums2 to nums1
        if (m < 0) {
            while (n >= 0) {
                nums1[n] = nums2[n];
                n--;
            }
        }

        while (m >= 0 && n >= 0) {
            // in reverse order and copy the largest value to the end of nums1
            while (m >= 0 && (n < 0 || nums1[m] > nums2[n])) {
                nums1[index--] = nums1[m--];
            }
            while (n >= 0 && (m < 0 || nums1[m] <= nums2[n])) {
                nums1[index--] = nums2[n--];
            }
        }
    }
};

int main() {
    Solution s;
    int a[] = {1,2,3,0,0,0};
    int b[] = {2,5,6};
    vector<int> nums1(a, a + sizeof(a) / sizeof(a[0]));
    vector<int> nums2(b, b + sizeof(b) / sizeof(b[0]));
    s.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
    return 0;
}