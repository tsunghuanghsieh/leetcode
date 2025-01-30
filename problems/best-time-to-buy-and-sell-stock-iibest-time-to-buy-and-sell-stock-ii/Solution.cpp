#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
