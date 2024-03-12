#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // In the initial approach, I failed to come up with a code flow which would allow elimination of computations
    // of previously discarded subtrees and tried to manually maintain the unique permutations of coins.
    // It failed LTE.
    // Also the amount was in the outer loop, coin in the inner loop
    vector<int> lcoins;
    vector<vector<int>> res;
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;   // special case
        lcoins = coins;
        res.assign(lcoins.size(), vector<int>(amount + 1, -1));
        sort(lcoins.begin(), lcoins.end());   // sorted coins will allow pruning
        return findChange(amount, 0);
    }
private:
    int findChange(int amount, int idx) {
        if (idx == lcoins.size() || amount < lcoins[idx]) return 0;
        if (amount == lcoins[idx]) return 1;
        if (res[idx][amount] != -1) return res[idx][amount];
        res[idx][amount] = findChange(amount - lcoins[idx], idx) + findChange(amount, idx + 1);
        return res[idx][amount];
    }
};
