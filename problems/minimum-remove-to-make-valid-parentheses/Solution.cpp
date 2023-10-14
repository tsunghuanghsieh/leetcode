#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> open;
        vector<int> close;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open.push_back(i);
            }
            else if (s[i] == ')') {
                if (open.size() > 0) open.pop_back();
                else close.push_back(i);
            }
        }
        // open parenthese exists only when there is no corresponding close parenthese thereafter
        // hence their indices are later in the string
        for (int i = open.size() - 1; i >= 0; i--) {
            s.erase(open[i], 1);
        }
        // close parenthese exists only when there is no corresponding open parenthese before
        // hence their indices are smaller in the string
        for (int i = close.size() - 1; i >= 0; i--) {
            s.erase(close[i], 1);
        }
        return s;
    }
};