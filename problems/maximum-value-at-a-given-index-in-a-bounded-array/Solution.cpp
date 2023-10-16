#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int maximized = 1;
        int l_max_height = index - 0, r_max_height = n - index;
        int l = 0, m = 0, r = 0, l_height = 0, r_height = 0, l_sum = 0, r_sum = 0, sum = l_sum + r_sum;
        while (n + l_sum + r_sum < maxSum) {
            l_sum = (l + m - 1) * l_height / 2.0;
            r_sum = (r + m) * r_height / 2.0;
            if (n + l_sum + r_sum >= maxSum) {
                if (n + l_sum + r_sum > maxSum) m--;
                break;
            }
            if (l_height + r_height == n) {
                m += floor((maxSum - n - l_sum - r_sum + 0.0) / n);
                break;
            }
            m++;
            if (m > 1 && l_height < l_max_height) {
                l_height++;
                l = 1;
            }
            else {
                l++;
            }
            if (r_height < r_max_height) {
                r_height++;
                r = 1;
            }
            else {
                r++;
            }
        }
        return maximized + m;
    }
};