#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
    static bool sortVector(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];
    };
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>> result;

        // special cases
        if (intervals.empty() || intervals.size() == 0) return result;

        // incurring O(nlogn) runtime complexity
        sort(intervals.begin(), intervals.end(), sortVector);
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < size; i++) {
            if (intervals[i][0] > end) {
                // disjoint
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                // overlap
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start, end});
        return result;
    }
};

int main() {
    Solution s;
    // vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals = {{2,4},{1,5},{1,3},{4,10},{16,18}};
    intervals = s.merge(intervals);
    cout << "[";
    for (int i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    return 0;
}