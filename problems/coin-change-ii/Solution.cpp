#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // In the initial top-down approach, I failed to come up with a code flow which would allow elimination
    // of computations of previously discarded subtrees and tried to manually maintain the unique permutations
    // of coins. It failed LTE.
    // Also the amount was in the outer loop, coin in the inner loop.
    // For Top-Down approach, it doesn't compute all numbers in amount, only those divisible by combinations
    // of coins. Its best exec time is faster the Bottom-up approach on LC.
    int change(int amount, vector<int>& coins) {
        // Bottom-up approach
        // Runtime is O(coins.size() * amount)
        vector<vector<int>> res(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= coins.size(); i++) res[i][0] = 1;
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i - 1] > j) res[i][j] = res[i - 1][j];
                else res[i][j] = res[i][j - coins[i - 1]] + res[i - 1][j];
            }
        }
        return res[coins.size()][amount];
    }
};
