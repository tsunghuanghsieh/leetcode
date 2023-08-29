#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0, shortest = INT_MAX;
        if (strs.size() == 1) return strs[0];
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < shortest) {
                shortest = strs[i].size();
                idx = i;
            }
        }
        if (!shortest) return "";
        for (int i = 0; i < strs[idx].size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (j == idx) continue;
                if (strs[j][i] != strs[idx][i]) return strs[idx].substr(0, i);
            }
        }
        return strs[idx];
    }
};