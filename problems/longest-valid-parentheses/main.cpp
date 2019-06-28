#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index;
        int start = -1, length = 0, longest = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                index.push(i);
            } else {
                if (index.size() > 0) {
                    index.pop();
                    length = (index.size() > 0) ? i - index.top() : i - start;
                    longest = max(longest, length);
                } else {
                    start = i;
                }
            }
        }
        return longest;
    }
};

int main() {
    // string input = "(()(()";
    string input = ")()(((())))(";
    Solution s;
    cout << s.longestValidParentheses(input) << endl;
    return 0;
}