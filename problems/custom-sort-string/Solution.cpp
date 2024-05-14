#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// while all characters in order are unique, characters in s are not.
// If order is "cba", and s is "eabcdabce", all c must come before b which come before a.
// Some of the acceptable permutations are "edccbbaae" and "ccbbaadee".
// It doesn't have to preserve the order of characters not in the order string.
class Solution {
public:
    string customSortString(string order, string s) {
        stringstream ss;
        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c : order) {
            ss << string(count[c - 'a'], c);
            count[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) ss << string(count[i], 'a' + i);
        }
        return ss.str();
    }
};
