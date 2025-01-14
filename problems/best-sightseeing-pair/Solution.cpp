#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Naive approach results in expected TLE error.
    int maxScoreSightseeingPair(vector<int>& values) {
        int output = 0, n = values.size() - 1;
        vector<int> fLeft(n), fRight(n);
        fLeft[0] = values[0];
        fRight[n - 1] = values[n] - n;
        for (int i = 1, j = n - 2; i < n; i++, j--) {
            fLeft[i] = max(fLeft[i - 1], values[i] + i);
            fRight[j] = max(fRight[j + 1], values[j + 1] - (j + 1));
        }
        for (int i = 0; i < n; i++) {
            output = max(output, fLeft[i] + fRight[i]);
        }
        return output;
    }
};
