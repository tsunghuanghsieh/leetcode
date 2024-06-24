#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution2 {
// 3rd attempt with space optimization in addition to memoization
// Runtime O(s.size()^2) and space O(s.size())
// itr 1           itr 2           itr 3           itr 4           itr 5           itr 6
// a b c d e c a   a b c d e c a   a b c d e c a   a b c d e c a   a b c d e c a   a b c d e c a
// 0 1             0 1 2           0 1 2 3         0 1 2 3 4       0 1 2 3 4 3     0 1 2 3 4 3 2
//   0 1             0 1 2           0 1 2 3         0 1 2 3 2       0 1 2 3 2 3     0 1 2 3 2 3
//     0 1             0 1 2           0 1 2 1         0 1 2 1 2       0 1 2 1 2       0 1 2 1 2
//       0 1             0 1 2           0 1 2 3         0 1 2 3         0 1 2 3         0 1 2 3
//         0 1             0 1 2           0 1 2           0 1 2           0 1 2           0 1 2
//           0 1             0 1             0 1             0 1             0 1             0 1
//             0               0               0               0               0               0
// At each iteration, it goes from bottom right to top left.
// At itr 1 and 2, both i and j are different, we have to remove the number of characters in order to
// make the substring i to j a paladrome. The number is (1 + min(j, j - 1)) from the previous iteration.
// At itr 3, i = 2 (c), j = 5 (c), we only need to remove 1 character, same as
// i = 3 and j = 4 at itr 1 (2 ietrations earlier). Similarly at itr 4, i = 1, j = 5.
// At the end of iterations, memo[s.size() - 1] has the minimum number of characters removed to have
// a paladrome.
//
// LC Editorial soln 3 achieves runtime O(s.size()^2) and space O(s.size()) complexity. It just uses 1x
// for memoization and constant for temp and prev (prev1 and prev2 respectively in my implementation).
// At each iteration, it goes from top to bottom.
// itr 1           itr 2           itr 3           itr 4           itr 5           itr 6
// a b c d e c a   a b c d e c a   a b c d e c a   a b c d e c a   a b c d e c a   a b c d e c a
// 0               0               0               0               0               0
//   0               0               0               0               0             1 0
//     0               0               0               0             1 0           2 1 0
//       0               0               0             1 0           2 1 0         3 2 1 0
//         0               0             1 0           2 1 0         3 2 1 0       4 3 2 1 0
//           0             1 0           2 1 0         1 2 1 0       2 1 2 1 0     3 2 1 2 1 0
//           1 0           2 1 0         3 2 1 0       2 3 2 1 0     3 2 3 2 1 0   2 3 2 3 2 1 0
public:
    bool isValidPalindrome(string s, int k) {
        if (s.size() == 1 || k >= s.size() - 1) return true;
        vector<int> memo(s.size()), prev1(s.size()), prev2(s.size());

        for (int i = 1; i < s.size(); i++) {
            for (int j = s.size() - 1; j >= i; j--) {
                memo[j] = (s[j] != s[j - i]) ? min(memo[j], memo[j - 1]) + 1 : prev2[j - 1];
            }
            if (i > 1) prev2.assign(prev1.begin(), prev1.end());
            prev1.assign(memo.begin(), memo.end());
        }
        return memo[s.size() - 1] <= k;
    }
private:
    // Helper function
    void printMemo(vector<int> memo) {
        for (int i = 0; i < memo.size(); i++) {
            cout << setprecision(3) << setw(2) << fixed << memo[i] << " ";
        }
        cout << endl;
    }
};
