#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        return isPalindrome(s, 0);
    }
private:
    bool isPalindrome(string s, int level) {
        for (int front = 0, back = s.size() - 1; front <= back; front++, back--) {
            if (s[front] != s[back] && level != 0) return false;
            if (s[front] != s[back]) {
                return isPalindrome(s.substr(front, back - front), ++level) ||
                       isPalindrome(s.substr(front + 1, back - front), ++level);
            }
        }
        return true;
    }
};