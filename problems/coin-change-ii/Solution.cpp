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
    // of coins. Its best exec time (0 ms) is faster the Bottom-up approach on LC wo space optimization (7 ms).
    // Bottom-up approach with space optimization runs at 0 ms more frequently than Top-down approach.
    int change(int amount, vector<int>& coins) {
        // Bottom-up approach
        // Runtime is O(coins.size() * amount)

        // To compute values of current row (coins[idx]), it needs res[i][j - coins[idx]] and res[i - 1][j].
        // We can add the values and store the result in the current row, hence reducing 2D array into 1D array.
        vector<int> res(amount + 1, 0);
        res[0] = 1;
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = coins[i - 1]; j <= amount; j++) {
                res[j] = res[j - coins[i - 1]] + res[j];
            }
        }
        return res[amount];
    }
};
