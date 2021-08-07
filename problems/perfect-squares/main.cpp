#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 50); // 50 is a some arbitrary for number of perfect squares

        // dp(12) = min{ dp(12 - 1 * 1) + 1, dp(12 - 2 * 2) + 1, dp(12 - 3 * 3) + 1}
        //        = min{ dp(11) + 1, dp(8) + 1, dp(3) + 1}
        // dp(11) = min{ dp(11 - 1 * 1) + 1, dp(11 - 2 * 2) + 1, dp(11 - 3 * 3) + 1}
        //        = min{ dp(10) + 1, dp(7) + 1, dp(2) + 1}
        // dp(10) = min{ dp(10 - 1 * 1) + 1, dp(10 - 2 * 2) + 1, dp(10 - 3 * 3) + 1}
        //        = min{ dp(9) + 1, dp(6) + 1, dp(1) + 1}
        // so on and so forth.

        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;

    cout << s.numSquares(28) << endl;
    return 0;
}