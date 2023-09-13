#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // special case
        if (s.size() != goal.size()) return false;

        for (int i = goal.size() - 1; i >= 0; i--) {
            // Use last char in s as anchor and try to match from the end of goal
            // When found, get the substr from 0 to the matching char in goal and
            // compare it against the same length of substr from last char in s.
            // Also get the substr from the matching char to the end in goal and
            // compare it against the same length of substr from 0 in s.
            // If both matches, return true. Otherwise, move on to find the next
            // matching char in goal.
            if (s[s.size() - 1] == goal[i]) {
                if (s.compare(s.size() - i - 1, i + 1, goal.substr(0, i + 1)) == 0 &&
                    s.compare(0, s.size() - i - 1, goal.substr(i + 1, goal.size() - i)) == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};