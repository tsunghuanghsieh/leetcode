#include <string>

using namespace std;

// This is similar to Fibonacci sequence from the first solution.
// Code is much easier to understand when the growth pattern is identified at each iteration.
//
// From i = 1, at each iteration, the number of rows will be the sum of prev1 and prev2
// when their respective condition is true.
// If none of the conditions are true, there is no way to decode the letters.
//--------------------------------------------------
// 121212 (both conditions are true)
//--------------------------------------------------
// 1 | 1  2 | 1  2  1 | 1  2  1  2 | 1  2  1  2  1 |
//   |   12 |   12  1 |   12  1  2 |   12  1  2  1 |
//   |      | 1    21 | 1    21  2 | 1    21  2  1 |
//   |      |         | 1  2    12 | 1  2    12  1 |
//   |      |         |   12    12 |   12    12  1 |
//   |      |         |            | 1  2  1    21 |
//   |      |         |            |   12  1    21 |
//   |      |         |            | 1    21    21 |
//--------------------------------------------------
// 121312 (one of the conditions is true)
//--------------------------------------------------
// 1 | 1  2 | 1  2  1 | 1  2  1  3 | 1  2  1  3  1 |
//   |   12 |   12  1 |   12  1  3 |   12  1  3  1 |
//   |      | 1    21 | 1    21  3 | 1    21  3  1 |
//   |      |         | 1  2    13 | 1  2    13  1 |
//   |      |         |   12    13 |   12    13  1 |
//   |      |         |            |               |
//--------------------------------------------------
// 121302 (none of the condition is true)
//--------------------------------------------------
// 1 | 1  2 | 1  2  1 | 1  2  1  3 | 1  2  1  3    |
//   |   12 |   12  1 |   12  1  3 |   12  1  3    |
//   |      | 1    21 | 1    21  3 | 1    21  3    |
//   |      |         | 1  2    13 | 1  2    13    |
//   |      |         |   12    13 |   12    13    |
//   |      |         |            |               |
//--------------------------------------------------
class Solution2 {
public:
    int numDecodings(string s) {
        int prev1 = 1, prev2 = 1, num1 = 0, num2 = 0;
        if (s[0] == '0') return 0;
        for (int i = 1; i < s.size(); i++) {
            int curr = 0;
            num1 = s[i] - '0';
            num2 = (s[i - 1] - '0') * 10;
            if (num1 > 0) curr += prev1;
            if (num2 != 0 && num2 + num1 <= 26) curr += prev2;
            if (curr == 0) return 0;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
