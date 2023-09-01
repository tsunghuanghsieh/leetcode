#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0], profit = 0;

        for (int price : prices) {
            if (lowest > price) lowest = price;
            else profit = max(price - lowest, profit);
        }
        return profit;
    }
};