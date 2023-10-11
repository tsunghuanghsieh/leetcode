#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Runtime
// O(n log n) where n is the number of intervals in the input

class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), compareIntervals);

        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > end) {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start, end});
        return result;
    }
private:
    static bool compareIntervals(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];

        return a[0] < b[0];
    }
};
