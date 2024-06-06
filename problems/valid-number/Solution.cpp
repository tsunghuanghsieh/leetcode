#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        //
        // LC execution time is more than 1 second, while others are in single digit milliseconds.
        //
        // regex patternNumber("[+-]?(\\d*\\.\\d+|\\d+\\.\\d*|\\d+)([eE][+-]?\\d+)?");
        // sregex_token_iterator itr(s.begin(), s.end(), patternNumber);
        // return (itr != sregex_token_iterator()) ? (*itr).str().size() == s.size() : false;

        // bitmask
        // 0: no input
        // 1: has sign
        // 2: integer
        // 4: decimal
        // 8: exponent
        bool isValid = false;
        for (int i = 0; i < s.size(); i++) {
            if (state == 0) {
                // sign|.|digit
                isValid = isValidState0Input(s[i]);
            }
            else if (state == 1) {
                // .|digit
                isValid = isValidState1Input(s[i]);
            }
            else if (state < 4) {
                // .|digit|exponent
                isValid = isValidState23Input(s[i]);
            }
            else if (state == 4 || state == 5) {
                // digit
                isValid = isValidState45Input(s[i]);
            }
            else if (state >= 6 && state < 8) {
                // digit|exponent
                isValid = isValidState67Input(s[i]);
            }
            else if (state == 8) {
                // sign|digit
                isValid = isValidState8Input(s[i]);
            }
            else if (state > 8) {
                // digit
                isValid = isValidStateabInput(s[i]);
            }
            if (!isValid) return isValid;
        }
        //  2: integer
        //  3: integer with sign
        //  6: decimal
        //  7: decimal with sign
        // 10: exponent
        // 11: exponent with sign
        return state == 2 || state == 3 || state == 6 || state == 7 || state == 10 || state == 11;
    }
private:
    bool hasExponent = false, hasPeriod = false;
    int state = 0;

    bool isValidState0Input(char c) {
        if (!isSign(c) && !isdigit(c) && !isPeriod(c)) return false;
        state |= isSign(c) | isdigit(c) << 1 | isPeriod(c) << 2;
        return state;
    }

    bool isValidState1Input(char c) {
        if (!isdigit(c) && !isPeriod(c)) return false;
        state |= isdigit(c) << 1 | hasPeriod << 2;
        return state;
    }

    bool isValidState23Input(char c) {
        if (!isdigit(c) && !isPeriod(c) && !isExponent(c)) return false;
        if (hasExponent) state = 0;
        state |= isdigit(c) << 1 | hasPeriod << 2 | hasExponent << 3;
        return state;
    }

    bool isValidState45Input(char c) {
        if (!isdigit(c)) return false;
        state |= isdigit(c) << 1;
        return state;
    }

    bool isValidState67Input(char c) {
        if (!isdigit(c) && !isExponent(c)) return false;
        if (hasExponent) state = 0;
        state |= isdigit(c) << 1 | hasExponent << 3;
        return state;
    }

    bool isValidState8Input(char c) {
        if (!isSign(c) && !isdigit(c)) return false;
        state |= isSign(c) | isdigit(c) << 1;
        return state;
    }

    bool isValidStateabInput(char c) {
        if (!isdigit(c)) return false;
        state |= isdigit(c) << 1;
        return state;
    }

    inline bool isExponent(char c) {
        if (c == 'E' || c == 'e') hasExponent = true;
        return hasExponent;
    }

    inline bool isPeriod(char c) {
        if (c == '.') hasPeriod = true;
        return hasPeriod;
    }

    inline bool isSign(char c) {
        return (c == '+' || c == '-') ? true : false;
    }
};
