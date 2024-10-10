#include <iostream>
#include <map>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // 1 is a special case. 1^x is 1. So we need to count the number of 1s.
    // 3 is the max integer to have to the power of 16 (2^4) and still be a valid input integer, 10^9.
    // Its maximum elements in sequence is 9, [2,4,16,256,65536,256,16,4,2].
    // 13 is the max integer to have to the power of 8 (2^3) and still be a valid input integer, 10^9.
    // The maximum elements in sequence is 7, [13,169,28561,815730721,28561,169,13].
    // 177 is the max integer to have to the power of 4 (2^2) and still be a valid input integer, 10^9,
    // its max elements will be 5.
    // Understanding that, it helps narrowing down the scope.
    int maximumLength(vector<int>& nums) {
        int maxLen = 1;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (auto& [num, count] : freq) {
            if (count == 1) continue;   // it needs at least 2 to start a sequence
            // 1 is a special case, 1^x is 1.
            if (num == 1) maxLen = max(maxLen, freq[num] / 2 * 2 + ((freq[num] % 2 == 0) ? -1 : 1));
            else maxLen = max(maxLen, checkLength(freq, num));
        }
        return maxLen;
    }
private:
    int checkLength(const unordered_map<int, int>& freq, int num) {
        int maxLen = 2;
        int maxInput = pow(10, 9);
        long long next_num = num;
        while (1) {
            next_num *= next_num;
            if (next_num > maxInput) break;
            if (freq.count(next_num) == 0) {
                maxLen--;
                break;
            }
            else if (freq.at(next_num) == 1) {
                maxLen++;
                break;
            }
            maxLen += 2;
        }
        if (maxLen % 2 == 0) maxLen--;
        return maxLen;

        // int maxLen = 2;
        // int pow2idx = 4;
        // int pow2[] = {1, 2, 4, 8, 16};
        // if (num <= 3) {   // 3^16 < 10^9
        //     pow2idx = 4;
        // } else if (num <= 13) {   // 13^8 < 10^9
        //     pow2idx = 3;
        // } else if (num <= 177) {   // 177^4 < 10^9
        //     pow2idx = 2;
        // } else if (num <= 31622) {   // 31622^2 < 10^9
        //     pow2idx = 1;
        // } else {
        //     pow2idx = 0;
        // }
        // for (int i = 1; i <= pow2idx; i++) {
        //     if (num > 31622) break;   // 31622^2 < 10^9
        //     int next_num = pow(num, pow2[i]);
        //     if (freq.count(next_num) == 0) {
        //         maxLen--;
        //         break;
        //     }
        //     else if (freq.at(next_num) == 1) {
        //         maxLen++;
        //         break;
        //     }
        //     maxLen += (i == pow2idx) ? 1 : 2;
        // }
        // if (maxLen == 2) maxLen--;
        // return maxLen;
    }
};
