#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int profit = 0;
        int highest = prices[prices.size() - 1];
        int lowest = INT32_MAX;

        for (int i = prices.size() - 1; i >= 0; i--) {
            // going reverse order to get the highest price
            if (highest < prices[i]) {
                highest = prices[i];
                // reset lowest price since we have a new highest price
                lowest = INT32_MAX;
            }
            if (highest > prices[i]) lowest = min(lowest, prices[i]);
            profit = max(profit, highest - lowest);
        }
        return profit;
    }
};

int main() {
    Solution s;
    int a[] = {7,1,5,3,6,4};
    vector<int> prices(a, a + sizeof(a) / sizeof(a[0]));
    cout << s.maxProfit(prices) << endl;
    return 0;
}