#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
    // mapIntervals: map of intervals added so far
    // start: start time of the current interval
    // end: end time of the current interval
    static void mergeOverlapped(map<int, int> &mapIntervals, int start, int end) {
        auto itr = mapIntervals.upper_bound(start);
        while (itr != mapIntervals.end()) {
            // cout << "mergeOverlapped start " << start << " end " << end << " itr->first " << itr->first << " itr->second" << itr->second << endl;
            if (itr->first > end) break; // no overlap, we are done.
            if (mapIntervals[start] < itr->second) { // terminating end
                mapIntervals[start] = end = itr->second;
            }
            int temp = itr->first;
            itr = next(itr);
            // only delete element in map after iterator has been advanced
            // or it sets the iterator to the first element in the map
            mapIntervals.erase(temp);
        }
    }

    // static void printMapIntervals(map<int, int> &mapIntervals) {
    static void printMapIntervals(map<int, int> &mapIntervals) {
        auto itr = mapIntervals.begin();
        while (itr != mapIntervals.end()) {
            cout << "printing current [" << itr->first << "," << itr->second << "]" << endl;
            itr = next(itr);
        }
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mapIntervals;
        vector<vector<int>> result;

        // special cases
        if (intervals.empty() || intervals.size() == 0) return result;

        int start = intervals[0][0], end = intervals[0][1];

        mapIntervals[intervals[0][0]] = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            auto itr = mapIntervals.find(intervals[i][0]);
            if (itr != mapIntervals.end()) {
                start = intervals[i][0];
                end = intervals[i][1];
                if (mapIntervals[start] >= end) continue;
                mapIntervals[start] = end;
            } else {
                itr = mapIntervals.upper_bound(intervals[i][0]);
                start = intervals[i][0];
                end = intervals[i][1];
                if (itr != mapIntervals.begin()) {
                    // as long as it's not at the beginning of map
                    // we need to look at the previous smaller key
                    int prevStart = prev(itr)->first;
                    int prevEnd = prev(itr)->second;
                    if (prevEnd >= start) {
                        // overlapped
                        start = prevStart;
                        end = max(end, prevEnd);
                    }
                }
                mapIntervals[start] = end;
            }
            mergeOverlapped(mapIntervals, start, end);
        }

        auto itr = mapIntervals.begin();
        while (itr != mapIntervals.end()) {
            result.push_back({itr->first, itr->second});
            itr = next(itr);
        }
        return result;
    }
};
