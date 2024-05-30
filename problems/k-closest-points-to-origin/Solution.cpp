#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

        for (int i = 0; i < points.size(); i++) {
            q.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }
        for (int i = 0; i < k; i++) {
            vector<int> item = q.top();
            cout << item[1] << endl;
            res.push_back(points[item[1]]);
            q.pop();
        }
        return res;
    }
};
