#include <vector>

using namespace std;

// Boyer-Moore Voting Algorithm
// It counts the occurence of the majority element, minus the occurence of the rest.
// The only number left at the end of the loop is the majority element.
//
// Time O(n)
// Space O(1)

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, majority;
        for (int num : nums) {
            if (count == 0) {
                majority = num;
                count++;
            }
            else {
                if (majority == num) count++;
                else count--;
            }
        }
        return majority;
    }
};