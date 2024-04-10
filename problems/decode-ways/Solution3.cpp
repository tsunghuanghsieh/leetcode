#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution3 {
public:
    vector<int> seen;
    int numDecodings(string s) {
        seen.assign(s.size(), -1);
        return recursive(0, s);
    }

    int recursive(int idx, string& s) {
        if (idx == s.size()) return 1;
        if (s[idx] == '0') return 0;
        if (idx == s.size() - 1) return 1;
        if (seen[idx] >= 0) return seen[idx];

        int sum = recursive(idx + 1, s);
        if (stoi(s.substr(idx, 2)) <= 26) {
            sum += recursive(idx + 2, s);
        }
        seen[idx] = sum;
        return sum;
    }
};
