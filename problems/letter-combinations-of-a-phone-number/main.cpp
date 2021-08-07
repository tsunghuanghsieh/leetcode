#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<char> substr;
        vector<string> combo;
        if (!digits.size()) return combo;
        getAllPermutation(0, substr, digits, combo);
        return combo;
    }
private:
    // dfs to get all permutations
    void getAllPermutation(int pos, vector<char>& substr, const string& digits, vector<string>& combo) {
        if (pos == digits.size()) {
            combo.push_back({substr.begin(), substr.end()});
            return;
        }
        vector<string> mapped = tel_itoa(digits.at(pos));
        for (string s : mapped) {
            substr.push_back(*s.c_str());
            getAllPermutation(pos + 1, substr, digits, combo);
            substr.pop_back();
        }
    }

    vector<string> tel_itoa(const char& s) {
        if (s == '2') {
            return vector<string>({"a", "b", "c"});
        } else if (s == '3') {
            return vector<string>({"d", "e", "f"});
        } else if (s == '4') {
            return vector<string>({"g", "h", "i"});
        } else if (s == '5') {
            return vector<string>({"j", "k", "l"});
        } else if (s == '6') {
            return vector<string>({"m", "n", "o"});
        } else if (s == '7') {
            return vector<string>({"p", "q", "r", "s"});
        } else if (s == '8') {
            return vector<string>({"t", "u", "v"});
        } else {
            return vector<string>({"w", "x", "y", "z"});
        }
    }
};

int main() {
    // string input = "23";
    string input = "456";

    Solution s;
    vector<string> combo = s.letterCombinations(input);
    for (size_t i = 0; i < combo.size(); i++) {
        cout << combo.at(i);
        if (i + 1 < combo.size()) cout << ",";
    }
    cout << endl;

    return 0;
}