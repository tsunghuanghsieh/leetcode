#include <iostream>

using namespace std;

class Solution {
public:
    // LC soln 2: greedy approach
    // Since there is only 3 letters, we can explicitly compare among a, b, c, instead of using
    // priority_queue (LC soln 1) for count and letter.
    // If the letter count is the highest, or any of the other 2 letters has been used twice,
    // use the first available letter, decrement its count, increment its counter and reset the
    // counters of the other 2 letters.
    string longestDiverseString(int a, int b, int c) {
        int cnt_a = 0, cnt_b = 0, cnt_c = 0, cnt_itr = a + b + c;
        string res;
        for (int i = 0; i < cnt_itr; i++) {
            if (a >= b && a >= c && cnt_a < 2 || a > 0 && (cnt_b == 2 || cnt_c == 2)) {
                cnt_a++;
                a--;
                res += 'a';
                cnt_b = cnt_c = 0;
            }
            else if (b >= a && b >= c && cnt_b < 2 || b > 0 && (cnt_a == 2 || cnt_c == 2)) {
                cnt_b++;
                b--;
                res += 'b';
                cnt_a = cnt_c = 0;
            }
            else if (c >= a && c >= b && cnt_c < 2 || c > 0 && (cnt_a == 2 || cnt_b == 2)) {
                cnt_c++;
                c--;
                res += 'c';
                cnt_a = cnt_b = 0;
            }
            else {
                break;
            }
        }

        return res;
    }
};
