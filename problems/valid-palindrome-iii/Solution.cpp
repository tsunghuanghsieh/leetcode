#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // memoization of previously checked substrings
    // int is used instead of bool in order to differentiate between checked or not.
    vector<vector<int>> memo;
    bool isValidPalindrome(string s, int k) {
        if (s.size() == 1 || k >= s.size() - 1) return true;
        memo.resize(s.size(), vector<int>(s.size(), -1));
        return isValidPalindrome(s, 0, s.size() - 1) <= k;
    }

    // return the number of removed character
    int isValidPalindrome(string &s, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        if (i == j) return memo[i][j] = 0;
        if (i == j - 1) return memo[i][j] = s[i] != s[j];
        if (s[i] == s[j]) return memo[i][j] = isValidPalindrome(s, i + 1, j - 1);
        return memo[i][j] = 1 + min(isValidPalindrome(s, i + 1, j), isValidPalindrome(s, i, j - 1));
    }
private:
    // Helper function
    void printMemo(string& s) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                cout << setprecision(3) << setw(2) << fixed << memo[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
