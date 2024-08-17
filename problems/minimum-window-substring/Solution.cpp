#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // The approach is to identify letters in t and their frequency and filter s based on that to get
    // their positions in s. I failed to identify the pattern and used brute force to find the minimum
    // window substring. Even with memoization and pruning, it passes LC test case 224 (test6.txt), out
    // of 268 total. However, it is not able to pass LC test case 264 (test7.txt) TLE.
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int m = s.size(), n = t.size();
        int first = m, last = 0;
        int vs[52], vt[52];
        unordered_map<char, vector<int>> matches;
        vector<vector<int>> positions;
        vector<int> counts;
        res[0] = INT_MAX;
        for (int i = 0; i < 52; i++) vt[i] = vs[i] = 0;
        for (char c : t) {
            vt[(c - 'a' < 0) ? c - 'A' : c - 'a' + 26]++;
        }
        for (int i = 0; i < m; i++) {
            if (vt[(s[i] - 'a' < 0) ? s[i] - 'A' : s[i] - 'a' + 26] == 0) continue;
            vs[(s[i] - 'a' < 0) ? s[i] - 'A' : s[i] - 'a' + 26]++;
            matches[s[i]].emplace_back(i);
        }
        for (int i = 0; i < 52; i++) {
            if (vt[i] == 0) continue;
            if (vt[i] > vs[i]) return "";
            if (vt[i] == vs[i]) {
                char ch = (i < 26) ? 'A' + i : 'a' + i - 26;
                first = min(first, matches[ch][0]);
                last = max(last, matches[ch][matches[ch].size() - 1]);
            }
            else {
                positions.emplace_back(matches[(i < 26) ? 'A' + i : 'a' + i - 26]);
                counts.emplace_back(vt[i]);
            }
        }

        dfs(positions, 0, 0, counts, first, last);
        return s.substr(res[1], res[0] + 1);
    }
private:
    int res[3];
    set<pair<int, int>> memo;
    void dfs(vector<vector<int>>& positions, int r, int c, vector<int>& counts, int first, int last) {
        if (res[0] < last - first) return;
        if (memo.count(pair<int, int>(first, last)) > 0) return;
        if (r >= positions.size()) {
            memo.insert(pair<int, int>(first, last));
            res[0] = last - first;
            res[1] = first;
            res[2] = last;
            return;
        }

        if (c + counts[r] < positions[r].size()) {
            dfs(positions, r, c + 1, counts, first, last);
        }
        first = min(first, positions[r][c]);
        last = max(last, positions[r][c + counts[r] - 1]);
        dfs(positions, r + 1, 0, counts, first, last);
        memo.insert(pair<int, int>(first, last));
        return;
    }
};
