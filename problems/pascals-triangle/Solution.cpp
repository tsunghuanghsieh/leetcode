#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> result = {{1}, {1, 1}};
        for (int i = 2; i < numRows; i++) {
            vector<int> curr = result[i - 1];
            vector<int> next = {1};
            for (int idx = 1; idx < curr.size(); idx++) {
                next.emplace_back(curr[idx] + curr[idx - 1]);
            }
            next.emplace_back(1);
            result.emplace_back(next);
        }
        return result;
    }
};