#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution2 {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> um_t;
        for (char ch : t) um_t[ch]++;

        unordered_map<char, int> freq;
        int min_l = 0, min_r = INT_MAX;
        for (int l = 0, r =  0, count = 0; r < m; r++) {
            if (um_t.count(s[r])) {
                freq[s[r]]++;
                if (freq[s[r]] == um_t[s[r]]) count++;   // letter count in t met, increment count
                // all letters in t met,
                while (l <= r && count == um_t.size()) {
                    if (um_t.count(s[l])) {
                        if (min_r - min_l > r - l) {
                            min_r = r;
                            min_l = l;
                        }
                        if (--freq[s[l]] < um_t[s[l]]) count--;
                    }
                    l++;
                }
            }
        }
        return (min_r == INT_MAX) ? "" : s.substr(min_l, min_r - min_l + 1);
    }
};
