#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC Editorial soln 1
    // It uses a sliding window and keeps track of left (l) and right (r) edge of the window.
    // It keeps incrementing r until all letters in t are encountered in s. It will starts
    // incrementing l to tighten the sliding window to determine the minimum sliding window,
    // until some letter in t is missing. It then resumes incrementing r again. The process
    // repeats until end of s is reached.
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size(), distinct = 0;
        int at[52], freq[52];   // lightweight, compared to vector<int>
        for (int i = 0; i < 52; i++) at[i] = freq[i] = 0;   // required init
        for (char ch : t) at[(ch - 'a' < 0) ? ch - 'A' : ch - 'a' + 26]++;
        for (int i = 0; i < 52; i++) if (at[i] > 0) distinct++;   // count of distinct letters in t

        int min_l = 0, min_r = INT_MAX;
        for (int l = 0, r =  0, count = 0; r < m; r++) {
            int idx_r = (s[r] - 'a' < 0) ? s[r] - 'A' : s[r] - 'a' + 26;
            if (at[idx_r] > 0) {
                freq[idx_r]++;
                if (freq[idx_r] == at[idx_r]) count++;   // letter count in t met, increment count
                // all letters in t met
                while (l <= r && count == distinct) {
                    int idx_l = (s[l] - 'a' < 0) ? s[l] - 'A' : s[l] - 'a' + 26;
                    if (at[idx_l]) {
                        if (min_r - min_l > r - l) {
                            min_r = r;
                            min_l = l;
                        }
                        if (--freq[idx_l] < at[idx_l]) count--;
                    }
                    l++;
                }
            }
        }
        return (min_r == INT_MAX) ? "" : s.substr(min_l, min_r - min_l + 1);
    }
};
