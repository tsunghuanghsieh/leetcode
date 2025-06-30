#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
        // use sliding window
        deque<double> window(degrees.begin(), degrees.end());
        for (int i = 0; i < degrees.size(); i++) {
            double deg = degrees[i];
            while (window.size() > 0 &&
                ((deg - angle < 0 && window.front() >= deg && window.front() < deg - angle + 360) ||
                (deg - angle >= 0 && (window.front() >= deg || window.front() < deg - angle)))) {
                if (i > 0 && deg == degrees[i - 1]) break;
                window.pop_front();
            }
            window.emplace_back(deg);
            size = max(size, (int) window.size());
        }
        return res + size;
    }
};
