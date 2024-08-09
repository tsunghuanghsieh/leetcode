#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // In the current implementation, instead of the first implementation where finding permissible y age
    // in the second for loop and storing the info (total requests made for age y by users in vector<int>
    // ages) in a separate array, y[121], finding permissible y age is moved to the last for loop, y[121]
    // array is eliminated since the same information can be indirectly derived from ages_count array.
    int numFriendRequests(vector<int>& ages) {
        int count = 0;
        int ages_count[121];
        // 1 - 14 yo users can't send any requests
        for (int i = 15; i < 121; i++) ages_count[i] = 0;

        for (int age : ages) {
            // minimum age of x when (1/2 * x + 7) will be older than x
            if (age * 0.5 + 7 < age) ages_count[age]++;
        }
        for (int age = 15; age < 121; age++) {
            if (ages_count[age] == 0) continue;
            for (int a = age * 0.5 + 8; a <= age; a++) {
                if (ages_count[a] == 0) continue;
                // for users of the same age, request number is the edges of vertices
                // edges = vertices * (vertices - 1)
                // for users of different ages, request number is the product of the count
                // count = (count of age x) * (count of age y)
                count += ages_count[a] * (ages_count[age] - (age == a));
            }
        }
        return count;
    }
};
