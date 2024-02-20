#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < nums.size(); i++) {
            // priority_queue implemnts a max-heap. hence multiply by -1.
            pq.emplace(-nums[i]);
            if (pq.size() > k) pq.pop();
        }
        return -pq.top();
    }
};
