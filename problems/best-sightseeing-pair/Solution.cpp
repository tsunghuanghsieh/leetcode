#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // The approach is to keep track of the max of (values[i] + i) from index 0 to (values.size() - 2)
    // and (values[i] - i) from index (values.size() - 1) to 1, then add the 2 values together to find
    // the max value pair. Runtime complexity and space complexity is O(n).
    //
    // Naive approach results in expected TLE error. Runtime complexity is O(n^2) and space complexity
    // O(1).
    int maxScoreSightseeingPair(vector<int>& values) {
        int output = 0, n = values.size() - 1;
        vector<int> fLeft(n), fRight(n);   // max traversing from left and right respectively
        fLeft[0] = values[0];
        fRight[n - 1] = values[n] - n;
        for (int i = 1, j = n - 2; i < n; i++, j--) {
            // keeping track of the max value from left to values.size() - 1
            fLeft[i] = max(fLeft[i - 1], values[i] + i);
            // keeping track of the max value from right to index 1
            fRight[j] = max(fRight[j + 1], values[j + 1] - (j + 1));
        }
        for (int i = 0; i < n; i++) {
            output = max(output, fLeft[i] + fRight[i]);
        }
        return output;
    }
};
