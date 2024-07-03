#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> freq;

        // compress 1s into frequency and leave 0s as is
        for (int i = 0, sum = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (sum > 0) {
                    freq.emplace_back(sum);
                    sum = 0;
                }
                freq.emplace_back(0);
            }
            else {
                sum++;
                if (i + 1 == nums.size()) freq.emplace_back(sum);
            }
        }

        int count = 0, most = 0;
        for (int i = 0, start = 0; i < freq.size(); i++) {
            if (freq[i] > 0) {
                count += freq[i];
            }
            else if (k > 0) {
                count++;
                k--;
            }
            else {
                if (freq[start] != 0) {
                    count -= freq[start];
                    start += 2;
                }
                else start++;
            }
            most = max(most, count);
        }
        return most;
    }
};
