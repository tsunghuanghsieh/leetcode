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
        regex patternNumber("[+-]?(\\d*\\.\\d+|\\d+\\.\\d*|\\d+)([eE][+-]?\\d+)?");
        sregex_token_iterator itr(s.begin(), s.end(), patternNumber);
        return (itr != sregex_token_iterator()) ? (*itr).str().size() == s.size() : false;
    }
};
