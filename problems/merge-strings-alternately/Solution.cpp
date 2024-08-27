#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size(), shorter = min(l1, l2);
        string res;
        for (int i = 0; i < shorter; i++) {
            res.insert(res.end(), word1[i]);
            res.insert(res.end(), word2[i]);
        }
        res += (l1 > l2) ? word1.substr(l2) : word2.substr(l1);
        return res;
    }
};
