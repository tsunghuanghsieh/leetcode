#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class SparseVector {
public:
    unordered_map<int, int> data;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) data.emplace(pair(i, nums[i]));
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for (auto [key, val] : data) {
            if (vec.data.count(key)) sum += (val * vec.data[key]);
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);