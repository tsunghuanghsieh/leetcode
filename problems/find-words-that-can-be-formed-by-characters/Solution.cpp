#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        int sum = 0;

        for (char &c : chars) freq[c - 'a']++;
        for (string &word : words) {
            vector<int> curr(26, 0);
            bool good = true;
            for (char &c : word) {
                int pos = c - 'a';
                curr[pos]++;
                if (!freq[pos] || curr[pos] > freq[pos]) {
                    good = false;
                    break;
                }
            }
            if (good) sum += word.size();
        }
        return sum;
    }
};
