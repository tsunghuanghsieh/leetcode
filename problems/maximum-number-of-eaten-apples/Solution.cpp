#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // Runtime: O(nlogn) from priority_queue ops
    // Space: O(n) for priority_queue
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int total = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> expiry;   // greater for min heap

        for (int i = 0; i < days.size(); i++) {
            // remove expired apples from queue
            while (expiry.size() > 0 && i == expiry.top()[0]) expiry.pop();
            // push expiry day and i^th day, instead of number of apples on i^th day.
            // we can't update item in the priority_queue in place.
            // To update, we have to peek, pop, change and push.
            // So instead, I store i^th and update apples vector directly.
            if (days[i] > 0) expiry.push({i + days[i], i});
            // if there are apples in the queue, use 1 apple with the earliest expiry
            if (expiry.size() > 0) {
                apples[expiry.top()[1]]--;
                total++;
                if (apples[expiry.top()[1]] == 0) expiry.pop();
            }
        }
        int d = days.size();
        while (expiry.size() > 0) {
            while (expiry.size() > 0 && expiry.top()[0] <= d) expiry.pop();
            if (expiry.size() > 0) {
                apples[expiry.top()[1]]--;
                total++;
                if (apples[expiry.top()[1]] == 0) expiry.pop();
                d++;
            }
        }
        return total;
    }
};
