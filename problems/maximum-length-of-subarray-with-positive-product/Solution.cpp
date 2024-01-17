#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int lenCurr = 0, lenMax = 0, cntNeg = 0, start = 0;
        int posFirstNeg = -1, posLastNeg = -1;
        function<int(bool, int)> getLength = [&](bool isZero, int i) -> int {
            if (cntNeg % 2 == 0) {
                lenCurr = i - start + !isZero;
            }
            else {
                lenCurr = max(posLastNeg - start, i - (posFirstNeg + 1) + !isZero);
            }
            return (lenMax > lenCurr) ? lenMax : lenCurr;
        };
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                lenMax = getLength(true, i);
                if (lenMax >= nums.size() - i - 1) return lenMax;
                start = i + 1;
                cntNeg = 0;
                posFirstNeg = posLastNeg = -1;
            } else {
                if (nums[i] < 0) {
                    if (++cntNeg == 1) posFirstNeg = posLastNeg = i;
                    else posLastNeg = i;
                }
            }
        }
        return getLength(nums[nums.size() - 1] == 0, nums.size() - 1);
    }
};
