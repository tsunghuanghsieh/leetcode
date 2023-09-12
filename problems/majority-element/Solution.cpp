#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        int majority_count = nums.size() / 2;
        for (int num : nums) {
            if (majority_count < ++count[num]) {
                return num;
            }
        }
        // To resolve compiler warning. Should never reach here.
        return INT_MIN;
    }
};