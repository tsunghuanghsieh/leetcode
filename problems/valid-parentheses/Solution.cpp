#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
            // choosing map instead of if/else directly comparing/push/pop char literal for maintenability
            // sacrificing space.
            if (bracketPairs.end() != bracketPairs.find(c)) {
                stk.push(bracketPairs.at(c));
            }
            else {
                if (stk.empty() || c != stk.top()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
private:
    static const map<char, char> bracketPairs;
};

const map<char, char> Solution::bracketPairs = {{'[', ']'}, {'{','}'}, {'(', ')'}};
