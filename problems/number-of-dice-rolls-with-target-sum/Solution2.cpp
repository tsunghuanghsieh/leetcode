#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC Editorial soln #2: DP Bottom-up (reverse)
    // Runtime complexity is O(n * target * k)
    // Space complexity is O(n * target)
    // Example: n 3 k 3 target 5
    // Answer: 6
    //      initial          dice 3           dice 2           dice 1
    // sum  0 1 2 3 4 5  ->  0 1 2 3 4 5  ->  0 1 2 3 4 5  ->  0 1 2 3 4 5
    //      0 0 0 0 0 0  ->  0 0 0 0 0 0  ->  0 0 0 0 0 0  ->  6 3 1 0 0 0
    //      0 0 0 0 0 0  ->  0 0 0 0 0 0  ->  2 3 2 1 0 0  ->  2 3 2 1 0 0
    //      0 0 0 0 0 0  ->  0 0 1 1 1 0  ->  0 0 1 1 1 0  ->  0 0 1 1 1 0
    //      0 0 0 0 0 1  ->  0 0 0 0 0 1  ->  0 0 0 0 0 1  ->  0 0 0 0 0 1
    int numRollsToTarget(int n, int k, int target) {
        if (n * k < target || n > target) return 0;
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(target + 1, 0));

        dp[n][target] = 1;   // base case
        for (int dice = n - 1; dice >= 0; dice--) {
            for (int sum = 0; sum <= target; sum++) {
                int ways = 0;
                for (int face = 1; face <= min(k, target - sum); face++) {
                    ways = (ways + dp[dice + 1][sum + face]) % MOD;
                }
                dp[dice][sum] = ways;
            }
        }
        return dp[0][0];
    }
private:
    const int MOD = 1e9 + 7;
};
