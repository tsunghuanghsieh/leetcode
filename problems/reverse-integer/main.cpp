#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int remainder = 0;
        int reversed = 0;

        while (x != 0) {
            remainder = x % 10;
            // INT32_MAX is  2147483647 (10 digits)
            // INT32_MIN is -2147483648 (10 digits)
            if (reversed > INT32_MAX / 10 || (reversed == INT32_MAX / 10 && remainder > INT32_MAX % 10) ||
                reversed < INT32_MIN / 10 || (reversed == INT32_MIN / 10 && remainder < INT32_MIN % 10)) {
                return 0;
            }
            reversed = reversed * 10 + remainder;
            x /= 10;
        }
        return reversed;
    }
};

int main() {
    Solution s;
    // cout << 123 << endl;
    // cout << s.reverse(123) << endl;
    cout << INT32_MIN << endl;
    cout << s.reverse(INT32_MIN) << endl;

    return 0;
}