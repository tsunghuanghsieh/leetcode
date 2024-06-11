#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s(to_string(num));
        priority_queue<char> nums;   // max queue
        vector<int> digits(10);

        for (int i = 0; i < s.size(); i++) {
            nums.push(s[i]);
            int n = s[i] - '0';
            digits[n] = digits[n] * 10 + (i + 1);   // 1-based index to avoid using 2d array
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < nums.top()) {
                int n = nums.top() - '0';
                int idx = digits[n] % 10;
                s[idx - 1] = s[i];
                s[i] = '0' + n;
                break;
            }
            else if (s[i] == nums.top()) nums.pop();
        }
        return stoi(s);
    }
};
