
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int sum, minus_1 = 1, minus_2 = 0;
        for (int i = 2; i <= n; i++) {
            sum = minus_1 + minus_2;
            minus_2 = minus_1;
            minus_1 = sum;
        }
        return sum;
    }
};