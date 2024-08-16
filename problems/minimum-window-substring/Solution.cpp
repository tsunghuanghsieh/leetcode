#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int m = s.size(), n = t.size();
        int first = m, last = 0;
        int vs[52], vt[52];
        unordered_map<char, vector<int>> matches;
        vector<vector<int>> positions;
        vector<int> counts;
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
            positions.emplace_back(matches[(i < 26) ? 'A' + i : 'a' + i - 26]);
            counts.emplace_back(vt[i]);
        }

        dfs(positions, 0, 0, counts, first, last);
        return s.substr(q.top()[1], q.top()[2] - q.top()[1] + 1);
    }
private:
    set<pair<int, int>> memo;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;   // min priority queue
    void dfs(vector<vector<int>>& positions, int r, int c, vector<int>& counts, int first, int last) {
        if (memo.count(pair<int, int>(first, last)) > 0) return;
        if (r >= positions.size()) {
            memo.insert(pair<int, int>(first, last));
            q.push({last - first, first, last});
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
