#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        for (int i1 = 0; i1 < word1.size() && i1 / 2 < word2.size(); i1 += 2) {
            word1.insert(i1 + 1, 1, word2[i1 / 2]);
        }
        if (word1.size() / 2 < word2.size()) word1.append(word2.substr(word1.size() / 2));
        return word1;
    }
};
