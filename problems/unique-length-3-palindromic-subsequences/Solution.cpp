#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln #1, count letters in between, which  first identify unique letters in s,
    // then find first and the last index of each unique letter before couting the unique letters
    // between the first and the last index.
    // My initial approach is similar to LC Editorial soln #1.
    // The runtime complexity is O(n) and space complexity is O(1) since there are only 26 letters.
    //
    // LC Editorial soln #2 precompute the first and the last index of all 26 letters, the first
    // index is -1 if the letter is not in s. After that, count the unique letters between the first
    // and the last index.
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
