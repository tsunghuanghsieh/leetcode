#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> res;
        int idx_s = 0, idx_b = INT_MIN;
        queue<int> q_a;
        bool found_a, found_b, single_a = isSingleAlpha(a), single_b = isSingleAlpha(b);
        while (idx_s < s.size()) {
            found_a = (idx_s + a.size() > s.size()) ? false :
                (single_a) ? find_string(s, a, (res.size() ? res.back() : INT_MIN), idx_s) : find_string(s, a, idx_s);
            found_b = (idx_s + b.size() > s.size()) ? false :
                (single_b) ? find_string(s, b, idx_b, idx_s) : find_string(s, b, idx_s);
            if (found_a) q_a.push(idx_s);
            if (found_b) idx_b = idx_s;
            if (q_a.size() > 0 && q_a.front() + k < idx_s) q_a.pop();
            if (idx_b != INT_MIN && idx_b + k < idx_s) idx_b = INT_MIN;
            if ((found_a || found_b) && isWithinK(q_a, idx_b)) {
                while (q_a.size()) {
                    res.push_back(q_a.front());
                    q_a.pop();
                }
            }
            idx_s++;
        }

        return res;
    }
private:
    bool find_string(string &s, string &ab, int idx_s) {
        int idx = 0;
        while (idx < ab.size() && s[idx_s] == ab[idx]) {
            idx_s++;
            idx++;
        }
        return idx == ab.size();
    }

    bool find_string(string &s, string &ab, int prev, int idx_s) {
        if (prev + 1 != idx_s || prev == INT_MIN) return find_string(s, ab, idx_s);
        return (s.size() > idx_s + ab.size() - 1 && s[idx_s + ab.size() - 1] == ab[ab.size() - 1]);
    }

    bool isSingleAlpha(string s) {
        char a = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != a) return false;
        }
        return true;
    }

    bool isWithinK(queue<int>& q_a, int idx_b) {
        return q_a.size() > 0 && idx_b != INT_MIN;
    }
};
