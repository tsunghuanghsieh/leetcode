#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln #1: DP Topdown
    // My initial approach was to use (n + 1) * (k + 1) for space,
    // which can be reduced to (n + 1) * (target + 1).
    // Runtime complexity is O(n * target * k)
    // Space complexity is O(n * target)
    // Example: n 3 k 3 target 5
    //     0  1  2  3  4  5 ->  0  1  2  3  4  5 ->  0  1  2  3  4  5 ->  0  1  2  3  4  5 ->  0  1  2  3  4  5
    // 0: -1 -1 -1 -1 -1 -1 -> -1 -1 -1 -1 -1 -1 -> -1 -1  1 -1 -1 -1 -> -1 -1 -1 -1 -1 -1 -> -1 -1 -1 -1 -1 -1
    // 1: -1 -1 -1 -1 -1 -1 -> -1 -1 -1 -1 -1 -1 -> -1  3 -1 -1 -1 -1 -> -1  3  2 -1 -1 -1 -> -1  3  2  1 -1 -1
    // 2: -1 -1  1 -1 -1 -1 -> -1 -1  1  1 -1 -1 -> -1 -1  1  1  1 -1 -> -1 -1  1  1  1  0 -> -1 -1  1  1  1  0
    // 3: -1 -1 -1  0  0  1 -> -1 -1 -1  0  0  1 -> -1 -1 -1  0  0  1 -> -1 -1 -1  0  0  1 -> -1 -1 -1  0  0  1
    int numRollsToTarget(int n, int k, int target) {
        if (n * k < target || n > target) return 0;
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        return dp_topdown(n, k, target, 0);
    }
private:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int dp_topdown(int n, int k, int target, int sum) {
        int ways = 0;
        if (n == 0) return (target == sum) ? 1 : 0;
        // LC Editorial soln take min of k and (target - sum), instead of k
        for (int i = 1; i <= min(k, target - sum); i++) {
            dp[dp.size() - n][sum + i] = (dp[dp.size() - n][sum + i] != -1) ? dp[dp.size() - n][sum + i] :
                dp_topdown(n - 1, k, target, sum + i);
            ways = (ways + dp[dp.size() - n][sum + i]) % MOD;
        }
        return ways;
    }
};
