#include <string>

using namespace std;

class Solution {
public:
    // Non dynamic programming approach (won't be able to identify Fibonacci sequence pattern during interview)
    //
    // When the value of the current char can be combined with the next char to decode a different letter,
    // e.g., 121212..., the number of ways to decode can be determined with Fibonacci sequence,
    // until a terminating number is encountered, 0 or values >= 3. In which case, a reset happens.
    //
    // To get the total number of ways, we need to multiply all results of Fibonacci sequence.
    int numDecodings(string s) {
        int fib = 1;
        int prev1 = 1 /* last number */, prev2 = 1 /* second last number */;   // for Fibonacci sequence
        int num1 = 0, num2 = 0, reset = 1;
        char curr = 0;
        for (string::iterator itr(s.begin()); itr != s.end(); itr++) {
            curr = *itr;
            num1 = curr - '0';
            if (num2 + num1 == 0) return 0;   // s[0] or first char after reset is 0.
            if (reset == 1) {
                if (num1 < 3) {
                    num2 = num1 * 10;
                    reset = 0;
                } else {
                    reset = prev1 = prev2 = 1;
                }
                continue;
            }
            if (num1 >= 3 || num1 == 0) {
                // Terminating current Fibonacci sequence
                if (num1 + num2 > 26) {
                    fib *= prev1;
                }
                else {
                    if (num1 == 0) {
                        // (1|2)*10 or (1|2)*20
                        // e.g., 1210 can be decoded [1, 2, 10] or [12, 10], not [1, 21, 0].
                        // so we need to revert the last update of Fibonacci sequence.
                        prev2 = prev1 - prev2;
                        prev1 = prev1 - prev2;
                        fib *= prev1;
                    }
                    else {
                        // For 11 to 26, inclusive, except 20.
                        prev1 += prev2;
                        fib *= prev1;
                    }
                }
                // reset
                num2 = 0;
                reset = prev1 = prev2 = 1;
            }
            else {
                num2 = num1 * 10;
                // updating for Fibonaci sequence
                prev1 += prev2;
                prev2 = prev1 - prev2;
            }
        }
        fib *= prev1;
        return fib;
    }
};
