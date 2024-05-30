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

//
// LC Editorial binary search approach
// First run through the array of points to calculate Euclidean distances from origin.
// Euclidean distances is used instead of Euclidean distances squared or the distribution may not be even.
// Find inital mid = lowest + (highest - lowest) / 2
// Run through the Euclidean distance to sort them into shorter or longer bucket against mid.
// If shorter bucket is more than k, highest = mid, find new mid
// and run against the shorter bucket.
// If shorter bucket is less or equal to k, reduce k by shorter bucket size, lowest = mid, find new mid
// and run aginst the longer bucket. Repeat until k is 0.
// Worst case runtime is O(n^2), however the average is O(n). Space O(n).
//
// LC Editorial also provides QuickSelect approach, or partial application of QuickSort. It will probably
// take too much time to implement during one-hour interview.
//