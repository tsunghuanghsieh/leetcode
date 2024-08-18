#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // Based on LC Editorial solutions, I can use sliding window to keep track of distinct letters in t
    // encountered in s in their own queue, instead of vector<int> then brute forcing my way through in
    // my initial approach. Once all letters in t are encountered in s, it can calculate the minimum
    // sliding window for the first time. Subsequently another letter in t is encountered, the corresponding
    // queue is updated and the minimum sliding window is recalculated.
    // Array is used instead of vector in order to pass LC test case 265 (test8.txt) TLE.
    //
    // The initial approach is to identify letters in t and their frequency and filter s based on that to get
    // their positions in s. I failed to identify the pattern and used brute force to find the minimum
    // window substring. Even with memoization and pruning, it passes LC test case 224 (test6.txt), out
    // of 268 total. However, it is not able to pass LC test case 264 (test7.txt) TLE.
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size(), first = m, last = 0, distinct = 0;
        int at[52];   // lightweight, compared to vector<int>
        queue<int> matches[52];
        unordered_set<char> matches_set;
        for (int i = 0; i < 52; i++) at[i] = 0;   // required init
        for (char ch : t) at[(ch - 'a' < 0) ? ch - 'A' : ch - 'a' + 26]++;
        for (int i = 0; i < 52; i++) if (at[i] > 0) distinct++;   // count of distinct letters in t
        for (int i = 0; i < m; i++) {
            int idx = (s[i] - 'a' < 0) ? s[i] - 'A' : s[i] - 'a' + 26;
            if (at[idx] > 0) {
                matches[idx].push(i);
                matches_set.insert(s[i]);   // count
                if (matches[idx].size() > at[idx]) matches[idx].pop();   // pop the oldest
                if (matches_set.size() == distinct) {
                    int local_first = m, local_last = 0, count = 0;
                    for (int j = 0; j < 52; j++) {
                        if (at[j] == 0) continue;   // letters in s but not in t
                        if (matches[j].size() < at[j]) break;   // letters in both s and t, but short
                        count++;
                        local_first = min(local_first, matches[j].front());
                        local_last = max(local_last, matches[j].back());
                    }
                    if (count == matches_set.size() && abs(last - first) > local_last - local_first) {
                        first = local_first;
                        last = local_last;
                    }
                }
            }
        }
        return (first == m && last == 0) ? "" : s.substr(first, last - first + 1);
    }
};
