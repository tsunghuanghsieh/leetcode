#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1) return x;
        if (x == -1) return (n % 2) ? x : -x;
        if (n == 0) return 1;
        double result = 1;
        // INT32_MAX is  2147483647 (10 digits)
        // INT32_MIN is -2147483648 (10 digits)

        // Using naive approach will end in time limit exceeded (TLE) when the exponent is huge.
        // Given the properties of exponent in multiplication, e.g., x^2 * x^4 = x^6.
        // x^2147483647 can be broken down to x^1073741823 * x^1073741823 * x^1 => (x^2)^1073741823 * x^1.
        // https://saturncloud.io/blog/how-to-explain-the-algorithm-for-calculating-the-power-of-a-number/

        while (abs(n / 2) > 0) {
            if (abs(n % 2) == 1) result *= x;
            x *= x;
            n /= 2;
        }
        result *= x;
        return (n > 0) ? result : 1.0 / result;
    }
};