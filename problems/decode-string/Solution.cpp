#include <iostream>

using namespace std;

class Solution {
public:
    // This implementation is similar to LC Editorial #3.
    // Runtime complexity is O(maxK * n), maxK is the maximum value of k and n is s.size().
    // Space complexity is O(s.size()), since it will be the max depth of recursive call stack.
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
private:
    string decodeString(string& s, int &i) {
        string res, str;
        int count = 0;

        for (; i < s.size(); i++) {
            if (isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
            }
            else if (isalpha(s[i])) {
                res += s[i];
            }
            else if (s[i] == '[') {
                str += decodeString(s, ++i);
                for (int j = 0; j < count; j++) res += str;
                count = 0;
                str.clear();
            }
            else break;   // for ]
        }
        return res;
    }
};
