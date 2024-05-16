#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int s1, e1, s2, e2;
        for (vector<vector<int>>::iterator itr1 = firstList.begin(), itr2 = secondList.begin();
            itr1 != firstList.end() && itr2 != secondList.end();) {
            s1 = itr1->data()[0];
            e1 = itr1->data()[1];
            s2 = itr2->data()[0];
            e2 = itr2->data()[1];
            int intervali = -1, intervalj = -1;
            // two intervals overlap
            if (s1 <= e2 && s2 <= e1) {
                intervali = max(s1, s2);
                intervalj = min(e1, e2);
                res.push_back({intervali, intervalj});
            }
            if ((intervalj == -1 && e1 < e2) || intervalj == e1) itr1++;
            if ((intervalj == -1 && e1 > e2) || intervalj == e2) itr2++;
        }
        return res;
    }
};
