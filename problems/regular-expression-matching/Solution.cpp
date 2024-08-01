#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
private:
    unordered_map<int, unordered_map<int, bool>> checked;
    bool isMatch(string& s, int si, string& p, int pi) {
        int ssize = s.size(), psize = p.size();
        char lookAhead = 0;

        if (checked[si].count(pi) > 0) return checked[si][pi];
        if (si == ssize && pi == psize) return true;
        if (si < ssize && pi == psize) return false;

        if (pi + 1 < psize) lookAhead = p[pi + 1];
        if (lookAhead == '*') {
            // case: no more s or (a-z and different)
            if (si == ssize || (p[pi] != '.' && p[pi] != s[si])) checked[si][pi] = isMatch(s, si, p, pi + 2);
            // case: '.' or (a-z and same)
            else checked[si][pi] = isMatch(s, si, p, pi + 2) || isMatch(s, si + 1, p, pi);
        }
        else {
            // case: no more s or (a-z and different)
            if (si == ssize || (p[pi] != '.' && p[pi] != s[si])) checked[si][pi] = false;
            // case: '.' or (a-z and same)
            else checked[si][pi] = isMatch(s, si + 1, p, pi + 1);
        }

        return checked[si][pi];
    }
};
