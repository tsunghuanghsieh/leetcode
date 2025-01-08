#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        vector<int> dist(26), counts(26);
        vector<unordered_set<char>> pal3(26);
        for (char c : s) {
            dist[c - 'a']++;
            // expirical data shows that unordered_set runs slightly slower than vector usually on LC.
            for (int i = 0; i < 26; i++) {
                if (dist[i] == 0 || i == c - 'a' && dist[i] == 1) continue;
                if (i == c - 'a' && dist[i] > 1) counts[c - 'a'] = pal3[c - 'a'].size();
                pal3[i].insert(c);
            }
        }
        for (int i = 0; i < 26; i++) count += counts[i];
        return count;

        // int count = 0;
        // unordered_set<char> seen;
        // vector<int> counts(26);
        // vector<unordered_set<char>> pal3(26);
        // for (char c : s) {
        //     for (char cs : seen) {
        //         if (cs == c) counts[c - 'a'] = pal3[c - 'a'].size();
        //         pal3[cs - 'a'].insert(c);
        //     }
        //     seen.insert(c);
        // }
        // for (int i = 0; i < 26; i++) count += counts[i];
        // return count;
    }
};
