#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    static bool sortIntervals(vector<int> A, vector<int> B) {
        return A[0] < B[0];
    }

    static void printIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        for (int i = 0; i < size; i++) {
            cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]" << endl;
        }
    }
public:
    // This is similar to LC soln #2, chronological ordering.
    // In LC soln #2, it uses 2 vector<int> for start and end times. It goes through
    // start time vector to increment room count. It reduces room count when start
    // time is >= end time and increment end time vector index. At the end of start
    // time vector, it returns the room count.
    //
    // I used map<int, int>, start and end times as key, and frequency as value. I
    // then loop through map<int, int> to tally up the count.
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = intervals.size();
        int count = 0;
        int maxCount = 0;
        map<int, int> mapIntervals;

        if (intervals.empty() || intervals.size() == 0) return 0;
        if (intervals.size() == 1) return 1;

        for (int i = 0; i < size; i++) {
            if (mapIntervals.find(intervals[i][0]) != mapIntervals.end()) {
                mapIntervals[intervals[i][0]]++;
            } else {
                mapIntervals[intervals[i][0]] = 1;
            }
            if (mapIntervals.find(intervals[i][1]) != mapIntervals.end()) {
                mapIntervals[intervals[i][1]]--;
            } else {
                mapIntervals[intervals[i][1]] = -1;
            }
        }
        auto itr = mapIntervals.begin();
        while (itr != mapIntervals.end()) {
            count += itr->second;
            maxCount = max(maxCount, count);
            itr = next(itr);
        }
        return maxCount;
    }
};
