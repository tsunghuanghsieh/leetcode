#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // This approach is similar to LC Editorial soln #3.
    //
    // scan through the prices, keep going as long as the price is increasing until a lower price
    // is encountered, compute the difference btwn the high and low prices and reset.
    // Runtime complexity O(n) space complexity O(1)
    //
    // LC Editorial soln #3 increments sum at each index when the value is more than the previous
    // index.
    int maxProfit(vector<int>& prices) {
        int sum = 0, low = prices[0], high = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < high) {
                sum += (high - low);
                low = high = prices[i];
            }
            else if (prices[i] > high) {
                high = prices[i];
            }
        }
        return sum += (high - low);
    }
};
