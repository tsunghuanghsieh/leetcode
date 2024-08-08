#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int count = 0;
        int ages_count[121], y[121];
        for (int i = 0; i < 121; i++) ages_count[i] = y[i] = 0;

        for (int i = 0; i < ages.size(); i++) {
            // minimum age of x when (1/2 * x + 7) will be older than x
            if (ages[i] * 0.5 + 7 < ages[i]) ages_count[ages[i]]++;
            // permissible ages (a) that x can send a request to
            for (int a = ages[i] * 0.5 + 8; a < ages[i] || (a > 100 && ages[i] >= 100 && a < ages[i]); a++) {
                y[a]++;
            }
        }
        for (int i = 1; i < 121; i++) {
            if (ages_count[i] > 0) count += y[i] * ages_count[i];   // request count * age count
            if (ages_count[i] > 1) count += ages_count[i] * (ages_count[i] - 1);   // edges for vertices
        }
        return count;
    }
};
