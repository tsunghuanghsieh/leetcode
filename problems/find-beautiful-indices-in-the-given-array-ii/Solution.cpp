#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // My initial approach was in line with Knuth-Morris-Pratt (KMP) algorithm, which I wasn't aware of
    // at the time. I didn't hash out the exact algorithm, and thinking my initial implementation would
    // be clunky, I went with the brute force for the first iteration. Expectedly, it encountered TLE error.
    // My optimized version, still without knowing KMP algorithm, focuses on a specific case of string
    // a and b with identical alphabet, sorta a specialized KMP algorithm. This case happens to be used
    // in TLE test cases.
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> res;
        int idx_s = 0, idx_b = INT_MIN;   // just need the most recent index for b
        queue<int> q_a;   // need queue to find all beautiful indices for a
        bool found_a, found_b, single_a = isSingleAlpha(a), single_b = isSingleAlpha(b);
        while (idx_s < s.size()) {
            // there is no a when a.size() is longer the remaining length in s
            found_a = (idx_s + a.size() > s.size()) ? false :
                // string a with identical alphabet, just check one more character
                // if not, use the next index in s (this can be improved with KMP algorithm)
                (single_a) ? find_string(s, a, (res.size() ? res.back() : INT_MIN), idx_s) : find_string(s, a, idx_s);
            // there is no b when b.size() is longer the remaining length in s
            found_b = (idx_s + b.size() > s.size()) ? false :
                // string a with identical alphabet, just check one more character
                // if not, use the next index in s (this can be improved with KMP algorithm)
                (single_b) ? find_string(s, b, idx_b, idx_s) : find_string(s, b, idx_s);
            if (found_a) q_a.push(idx_s);
            if (found_b) idx_b = idx_s;
            // update when elements are outside the range k
            if (q_a.size() > 0 && q_a.front() + k < idx_s) q_a.pop();
            if (idx_b != INT_MIN && idx_b + k < idx_s) idx_b = INT_MIN;
            // finding beautiful indices
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
