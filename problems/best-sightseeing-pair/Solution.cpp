#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // LC soln #2 is elegant
    // It keep track of the max of (values[i] + i) up to index (i - 1) and add it to the current value
    // of (values[i] - i) for the max of the 2 values, then update the max of (values[i] + i) to the
    // current index i. Repeat it for index from i is 1 to values.size(). Runtime complexity is O(n)
    // and space complexity O(1).
    //
    // Naive approach results in expected TLE error. Runtime complexity is O(n^2) and space complexity
    // O(1).
    int maxScoreSightseeingPair(vector<int>& values) {
        // index  0  1  2  3  4
        // value  8  1  5  2  6
        // city a 8  8  8  8 10   8  8  8  8 10
        // city b    0  3 -1  2   0  3 -1  2
        //                        8 11  7 10
        int output = 0, maxLeft = values[0];
        for (int i = 1; i < values.size(); i++) {
            int city_a = values[i] + i, city_b = values[i] - i;
            output = max(output, maxLeft + city_b);
            maxLeft = max(maxLeft, city_a);
        }
        return output;

        // The approach is to keep track of the max of (values[i] + i) from index 0 to (values.size() - 2)
        // and (values[i] - i) from index (values.size() - 1) to 1, then add the 2 values together to find
        // the max value pair. Runtime complexity and space complexity is O(n).
        //
        // index 0 1 2 3 4
        // value 8 1 5 2 6
        // left  8 8 8 8     8  8  8  8
        // right   3 3 2 2   3  3  2  2
        //                  11 11 10 10
        // int output = 0, n = values.size() - 1;
        // vector<int> fLeft(n), fRight(n);   // max traversing from left and right respectively
        // fLeft[0] = values[0];
        // fRight[n - 1] = values[n] - n;
        // for (int i = 1, j = n - 2; i < n; i++, j--) {
        //     // keeping track of the max value from left to values.size() - 1
        //     fLeft[i] = max(fLeft[i - 1], values[i] + i);
        //     // keeping track of the max value from right to index 1
        //     fRight[j] = max(fRight[j + 1], values[j + 1] - (j + 1));
        // }
        // for (int i = 0; i < n; i++) {
        //     output = max(output, fLeft[i] + fRight[i]);
        // }
        // return output;
    }
};
