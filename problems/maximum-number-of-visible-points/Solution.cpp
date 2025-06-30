#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // My initial approach was to initialize deque with the degrees vector as is once, which
    // serves as the sliding window, and iterate through degrees to append to deque while
    // looking back and popping points outside of angle from the front of deque. This results
    // in convoluted condition statements which took a few attempts to get right.
    //
    // The solution found online was to duplicate the degrees with + 360 to handle circular
    // visibility. Then use 2 pointers to indicate sliding window. Duplicating degrees (+ 360)
    // simplifies the comparisons tremendously.
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int res = 0, size = 0;
        vector<double> degrees;
        for (int i = 0; i < points.size(); i++) {
            double x = points[i][0] - location[0], y = points[i][1] - location[1];
            double degree;
            if (x == 0 && y == 0) {
                res++;   // point on location, it will always be seen
                continue;
            }
            degree = atan2(y, x) * 180 / M_PI;
            if (degree < 0) degree += 360;   // convert to standard angle 0 - 360
            degrees.emplace_back(degree);
        }
        sort(degrees.begin(), degrees.end());
        // handle circular visibility
        int degrees_size = degrees.size();
        for (int i = 0; i < degrees_size; i++) degrees.emplace_back(degrees[i] + 360);
        // use sliding window
        for (int i = 0, j = 1; i < degrees_size; i++) {
            while (degrees[i] + angle >= degrees[j]) j++;
            size = max(size, j - i);
        }
        // Initial approach
        // deque<double> window(degrees.begin(), degrees.end());
        // for (int i = 0; i < degrees.size(); i++) {
        //     double deg = degrees[i];
        //     while (window.size() > 0 &&
        //         ((deg - angle < 0 && window.front() >= deg && window.front() < deg - angle + 360) ||
        //         (deg - angle >= 0 && (window.front() >= deg || window.front() < deg - angle)))) {
        //         if (i > 0 && deg == degrees[i - 1]) break;
        //         window.pop_front();
        //     }
        //     window.emplace_back(deg);
        //     size = max(size, (int) window.size());
        // }
        return res + size;
    }
};
