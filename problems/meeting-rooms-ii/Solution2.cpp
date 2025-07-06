#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

class Solution2 {
public:
    // This implementation uses min heap like LC soln #1. Both push end time to priority_queue.
    // In my implementation, I pop all end times that's >= to the new start time. Hence, I need
    // a separate maxCount. In LC soln #1, it only pops 1. In the end, it returns the size of
    // priority_queue. Instead of while loop (like mine), it uses if statement. It also does not
    // need a separate maxCount. It makes sense, albeit a little counterintuitive.
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int maxCount = 0;
        priority_queue<int, vector<int>, greater<int>> q;   // min heap

        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            while (q.size() > 0 && intervals[i][0] >= q.top()) q.pop();
            q.push(intervals[i][1]);
            maxCount = max(maxCount, (int) q.size());
        }
        return maxCount;
    }
};
