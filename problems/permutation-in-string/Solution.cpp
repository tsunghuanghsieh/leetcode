#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    // Coming after implementing Knuth-Morris-Pratt (KMP) algorithm, I was conditioned to jump the index
    // to the next valid starting index in s2, which evidently takes longer to execute on LC test cases
    // because of reevaluation of characters when the frequency of a seen character in s2 > s1.
    // This approach is similar to LC soln 4 and is probably faster because of the index jump and the use
    // of count, but slower than soln 5 and 6 which use sliding window.
    bool checkInclusion(string s1, string s2) {
        int s1_freq[26] = {};   // init array to 0
        int count_s1 = s1.size(), count_s2 = s2.size();
        if (count_s1 > count_s2) return false;

        for (int i = 0; i < count_s1; i++) s1_freq[s1[i] - 'a']++;

        int idx = 0;
        while (idx < count_s2) {
            queue<int> s1_indices[26];
            int count = 0;
            if (idx + count_s1 > count_s2) return false;
            for (; idx < count_s2; idx++) {
                if (s1_freq[s2[idx] - 'a'] > 0) {
                    s1_indices[s2[idx] - 'a'].push(idx);
                    if (s1_indices[s2[idx] - 'a'].size() > s1_freq[s2[idx] - 'a']) {
                        idx = s1_indices[s2[idx] - 'a'].front() + 1;
                        break;
                    }
                    if (++count == count_s1) return true;
                }
                else {
                    idx++;
                    break;
                }
            }
        }

        return false;
    }
};
