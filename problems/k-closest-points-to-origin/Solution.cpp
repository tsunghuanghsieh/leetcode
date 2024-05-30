#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>> q;   // max heap

        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            // cap size at k
            // runtime O(nlogk) and space O(k)
            // instead of O(nlogn) and O(n)
            if (q.size() == k) {
                if (dist >= q.top()[0]) continue;
                q.pop();
            }
            q.push({dist, i});
        }
        for (int i = 0; i < k; i++) {
            res.push_back(points[q.top()[1]]);
            q.pop();
        }
        return res;
    }
};
