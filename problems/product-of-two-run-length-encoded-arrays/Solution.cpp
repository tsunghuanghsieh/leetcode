#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Naive approach (expanding encoded to 1D array and multiply) will run into TLE at runtime in several TCs.
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> res;

        for (int i1 = 0, i2 = 0, s1 = encoded1[i1][1], s2 = encoded2[i2][1], last_prod = 0;
            i1 < encoded1.size() && i2 < encoded2.size();) {
            int smaller = min(s1, s2);
            s1 -= smaller;
            s2 -= smaller;
            int prod = encoded1[i1][0] * encoded2[i2][0];
            if (last_prod != prod) {
                res.push_back({prod, smaller});
                last_prod = prod;
            }
            else res[res.size() - 1][1] += smaller;
            if (s1 == 0) {
                i1++;
                if (i1 < encoded1.size()) s1 = encoded1[i1][1];
            }
            if (s2 == 0) {
                i2++;
                if (i2 < encoded2.size()) s2 = encoded2[i2][1];
            }
        }
        return res;
    }
};
