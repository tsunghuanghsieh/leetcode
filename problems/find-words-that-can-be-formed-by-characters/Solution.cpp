#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> freq;
        int sum = 0;

        for (char c : chars) freq[c]++;
        for (string word : words) {
            unordered_map<char, int> curr;
            bool good = true;
            for (char c : word) {
                curr[c]++;
                if (!freq.count(c) || curr[c] > freq[c]) {
                    good = false;
                    break;
                }
            }
            if (good) sum += word.size();
        }
        return sum;
    }
};
