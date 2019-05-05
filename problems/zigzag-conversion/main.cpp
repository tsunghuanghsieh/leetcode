#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string val;
    string convert(string s, int numRows) {
        int gaps[numRows][2];
        if (numRows == 1) gaps[0][0] = 1;   // special case
        for (int i = numRows - 1; i >= 0; i--) {
            // Please refer to Explanation in README.md
            if (i > 0) {
                gaps[i][0] = (numRows - 1) * 2 - (numRows - 1 - i) * 2;
                gaps[i][1] = (numRows - 1) * 2 - gaps[i][0];
            } else {
                gaps[i][0] = gaps[numRows - 1][0];
                gaps[i][1] = 0;
            }
        }
        for (int row = 0; row < numRows; row++) {
            for (int idx = row, pos = 0; idx < s.length(); idx+=gaps[row][pos]) {
                // all rows, except first and last rows, have 1 extra character between columns.
                // so for first and last row, [row][1] is set to 0 and do not try to append character.
                if ((row != 0 && row + 1 != numRows) || pos != 1) {
                    val += s[idx];
                }
                pos = (pos + 1) % 2;
            }
        }
        return val;
    }
};

int main() {
    string str = "PAYPALISHIRING";
    Solution s;
    cout << s.convert(str, 3) << endl;
    return 0;
}