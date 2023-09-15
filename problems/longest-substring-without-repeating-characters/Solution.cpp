#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> seen;
        int start = 0, longest = 0;

        for (int i = 0; i < s.size(); i++) {
            if (seen.find(s[i]) != seen.end()) {
                if (seen[s[i]] > start) start = seen[s[i]] + 1;
                if (seen[s[i]] == start) start++;
            }
            longest = (longest > i - start + 1) ? longest : i - start + 1;
            seen[s[i]] = i;
        }
        return longest;
    }
};