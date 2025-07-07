#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // My implementation is to sort points, and then get arctangent between all points. Sort
    // will limit the values of atan2 to only negative. Without sorting, I need to add pi to
    // values <= 0 to recognize atan2(-1, -1) and atan2(1, 1), atan2(-1, 1) and atan2(1, -1)
    // as a straight line. As the result of adding pi, it appears to introduces floating point
    // error and hence a different key in unordered_map<double, int>.
    //
    // atan2(-1,  1) = -0.785398... | atan2(1,  1) = 0.785398...
    // -----------------------------|---------------------------
    // atan2(-1, -1) = -2.35619...  | atan2(1, -1) = 2.35619...
    //
    // Using unordered_map<double, int> (key: atan2(y, x), floating point trigonometry) is
    // slower than unordered_map<pair<int, int>, int> (key: x / gcd(x, y), y / gcd(x, y)),
    // and is subject to floating point error. However, the code is cleaner.
    //
    // Runtime complexity: O(n^2)
    // Space complexity: O(n)
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end());
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> rads;
            for (int j = i + 1; j < points.size(); j++) {
                double rad = atan2(points[i][1] - points[j][1], points[i][0] - points[j][0]);
                // without sorting points above, uncomment the 2 lines below
                // if (rad <= 0.0) rad += M_PI;
                // rad = round(rad / 1e-10) * 1e-10;   // rounding to ensure precision
                rads[rad] += 1;
                res = max(res, rads[rad]);
            }
        }
        return ++res;
    }
};
