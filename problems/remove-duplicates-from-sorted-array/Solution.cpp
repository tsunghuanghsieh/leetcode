#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for (int curr = nums[0], next = 1, i = 1; i < nums.size(); i++) {
            if (curr != nums[i]) {
                nums[next++] = curr = nums[i];
                k++;
            }
        }
        return k;
    }
};