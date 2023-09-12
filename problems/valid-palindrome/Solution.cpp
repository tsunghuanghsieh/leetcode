#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sanitized_string;

        for (char c : s) {
            if (isalnum(c)) {
                sanitized_string += tolower(c);
            }
        }

        for (int i = 0; i < sanitized_string.size() / 2; i++) {
            if (sanitized_string[i] != sanitized_string[sanitized_string.size() - 1 - i]) return false;
        }
        return true;
    }
};