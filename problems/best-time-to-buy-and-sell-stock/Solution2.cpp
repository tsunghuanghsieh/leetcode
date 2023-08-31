#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0], highest = 0, profit = 0;

        for (int price : prices) {
            if (price < lowest) {
                profit = max(highest - lowest, profit);
                lowest = price;
                highest = 0;
            }
            else if (price > highest) {
                highest = price;
                profit = max(highest - lowest, profit);
            }
        }
        return profit;
    }
};