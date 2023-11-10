#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    // In the solution, it uses 1 to maxSum for l and r which obviates the 2 if statements after while loop.
    // I use bounds of array index (0 to n - 1 for l and r) to get the maximum sum.
    // If maximum sum is < maxSum after exiting the loop, we just need to add the quotient to the value.
    int maxValue(int n, int index, int maxSum) {
        int l = 0, r = n - 1;
        long sum = 0;

        while (l < r) {
            int mid = ceil((l + r) / 2.0);
            sum = getSum(index, mid + 1, n);
            if (sum <= maxSum) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        // sum is 0 when array size is 1.
        // l is the index, not value.
        if (sum != 0) l++;
        if (sum < maxSum) {
            l += (maxSum - sum) / n;
        }
        return l;
    }
private:
    double getSum(int index, int value, int n) {
        double sum = 0;
        int l = 1, r = 1;
        // right edge value
        if (value - (n - index - 1) > 1) {
            r = value - (n - index - 1);
        }
        // left edge value
        if (value - index > 1) {
            l = value - index;
        }
        // sum right of index
        sum += (value + r) * ((value - r + 1) / 2.0);
        if (r == 1) {
            sum += n - index - value;
        }
        // sum left of index
        sum += (l + value) * ((value - l + 1) / 2.0);
        if (l == 1) {
            sum += index - value + 1;
        }
        sum -= value;
        return sum;
    }
};