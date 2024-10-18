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
        bool found_a, found_b;
        while (idx_s < s.size()) {
            if (found_a = find_string(s, a, idx_s); found_a) q_a.push(idx_s);
            if (found_b = find_string(s, b, idx_s); found_b) idx_b = idx_s;
            if (q_a.size() > 0 && q_a.front() + k < idx_s) q_a.pop();
            if (idx_b + k < idx_s) idx_b = INT_MIN;
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

    bool isWithinK(queue<int>& q_a, int idx_b) {
        return q_a.size() > 0 && idx_b != INT_MIN;
    }
};
