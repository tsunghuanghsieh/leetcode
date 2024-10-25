#include <iostream>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    // LC soln 6 optimized sliding window implemention w reduced comparisons to find match
    bool checkInclusion(string s1, string s2) {
        int s1_freq[26], window[26], count_s1 = s1.size(), count_s2 = s2.size();

        if (count_s1 > count_s2) return false;

        for (int i = 0; i < count_s1; i++) {
            s1_freq[s1[i] - 'a']++;   // frequency of alphabets in s1
            window[s2[i] - 'a']++;   // sliding window. frequency of alphabets in s2 up to s1.size()
            s1_set.insert(s1[i] - 'a');   // reduce comparisons from 26 to alphabets found in s1
        }

        for (int i = 0; i + count_s1 < count_s2; i++) {
            if (find_match(s1_freq, window)) return true;
            // left border of the sliding window
            if (s1_set.count(s2[i] - 'a') > 0) window[s2[i] - 'a']--;
            // right border of the sliding window
            if (s1_set.count(s2[i + count_s1] - 'a') > 0) window[s2[i + count_s1] - 'a']++;
        }
        return find_match(s1_freq, window);
    }
private:
    unordered_set<int> s1_set;
    bool find_match(const int s1_freq[], const int window[]) {
        // instead of a-z, just compare against alphabets found in s1
        for (int num : s1_set) {
            if (s1_freq[num] != window[num]) return false;
        }
        return true;
    }
};
