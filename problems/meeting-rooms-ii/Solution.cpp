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
