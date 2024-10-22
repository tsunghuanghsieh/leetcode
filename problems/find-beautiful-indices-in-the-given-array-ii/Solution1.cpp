#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    // Knuth-Morris-Pratt (KMP) algorithm
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> occr_a = kmpSearch(s, a);
        vector<int> occr_b = kmpSearch(s, b);
        vector<int> res;

        int idx = 0;
        for (int idx_a : occr_a) {
            while (idx < occr_b.size() && occr_b[idx] < idx_a && occr_b[idx] + k < idx_a) idx++;
            if (idx == occr_b.size()) break;
            if (occr_b[idx] <= idx_a && occr_b[idx] + k >= idx_a) res.emplace_back(idx_a);
            if (occr_b[idx] > idx_a && occr_b[idx] - k <= idx_a) res.emplace_back(idx_a);
        }
        return res;
    }
private:
    // This returns the indices in string s of all occurences of string p using KMP
    vector<int> kmpSearch(const string &s, const string &p) {
        vector<int> prefix = computeStringPrefix(p), occr;
        for (int i = 0, j = 0; i < s.size(); i++) {
            while (j > 0 && s[i] != p[j]) j = prefix[j - 1];
            j++;
            if (j == p.size()) {
                if (s[i] == p[j - 1]) occr.emplace_back(i - p.size() + 1);
                j = prefix[j - 1];
            }
        }
        return occr;
    }

    // This computes the longest prefix in the string that are identical at each index
    // idx        0  1  2  3  4  5  6  7  8  9
    // str        a  b  c  d  a  b  c  d  a  x
    // prefix cnt 0  0  0  0  1  2  3  4  5  0
    vector<int> computeStringPrefix(const string &p) {
        vector<int> prefix(p.size(), 0);
        int longest_prefix = 0;
        for (int i = 1; i < p.size(); i++) {
            while (longest_prefix > 0 && p[longest_prefix] != p[i]) {
                longest_prefix = prefix[longest_prefix - 1];
            }
            if (p[longest_prefix] == p[i]) {
                longest_prefix++;
            }
            prefix[i] = longest_prefix;
        }
        return prefix;
    }
};
