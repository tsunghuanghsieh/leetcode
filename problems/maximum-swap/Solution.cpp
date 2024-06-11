#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s(to_string(num));
        priority_queue<char> nums;   // max queue. all digits seen in descending order.
        vector<int> digits(10);

        for (int i = 0; i < s.size(); i++) {
            nums.push(s[i]);
            digits[s[i] - '0'] = i;   // last index found for the digit
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < nums.top()) {
                s[digits[nums.top() - '0']] = s[i];
                s[i] = nums.top();
                break;
            }
            else if (s[i] == nums.top()) nums.pop();
        }
        return stoi(s);
    }
};
