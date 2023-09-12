#include <regex>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sanitized_string;
        regex pattern("[0-9a-zA-Z]+");
        sregex_token_iterator end;

        for (sregex_token_iterator itr(s.begin(), s.end(), pattern); itr != end; itr++) {
            string word = *itr;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            sanitized_string.append(word);
        }

        for (int i = 0; i < sanitized_string.size() / 2; i++) {
            if (sanitized_string[i] != sanitized_string[sanitized_string.size() - 1 - i]) return false;
        }
        return true;
    }
};