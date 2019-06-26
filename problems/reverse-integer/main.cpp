#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        bool negative = x < 0;
        vector<int> num, vmax, vmin;
        int overflow_max = INT32_MAX;
        int overflow_min = INT32_MIN;
        bool bMayOverflow = true;

        if (x == 0) return x;

        // INT32_MAX is  2147483647 (10 digits)
        // INT32_MIN is -2147483648 (10 digits)
        while (overflow_max / 10 != 0) {
            vmax.push_back(overflow_max % 10);
            vmin.push_back(abs(overflow_min % 10));
            overflow_max /= 10;
            overflow_min /= 10;
        }
        vmax.push_back(overflow_max);
        vmin.push_back(abs(overflow_min));

        while (x % 10 == 0) {
            x /= 10;
        }
        while (x / 10 != 0) {
            num.push_back(abs(x % 10));
            x /= 10;
        }
        num.push_back(abs(x));
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num.size() == 10 && bMayOverflow) {
                // overflow check
                if (!negative) {
                    if (num[num.size() - 1 - i] > vmax[i]) return 0;
                    if (num[num.size() - 1 - i] < vmax[i]) bMayOverflow = false;
                } else {
                    if (num[num.size() - 1 - i] > vmin[i]) return 0;
                    if (num[num.size() - 1 - i] < vmin[i]) bMayOverflow = false;
                }
            }
            reversed += (num[num.size() - 1 - i] * pow(10, i));
        }
        return reversed * ((negative) ? -1 : 1);
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