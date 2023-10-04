#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int /* row */ m = matrix.size(), /* column */ n = matrix[0].size();
        int size = m * n, top = 1, bottom = m - 1, left = 0, right = n - 1;
        int row = -1, col = -1;

        while (result.size() <= size) {
            for (col++, row++; col <= right; col++) {
                result.push_back(matrix[row][col]);
                if (result.size() == size) return result;
            }
            right--;
            for (row++, col--; row <= bottom; row++) {
                result.push_back(matrix[row][col]);
                if (result.size() == size) return result;
            }
            bottom--;
            for (col--, row--; col >= left; col--) {
                result.push_back(matrix[row][col]);
                if (result.size() == size) return result;
            }
            left++;
            for (row--, col++; row >= top; row--) {
                result.push_back(matrix[row][col]);
                if (result.size() == size) return result;
            }
            top++;
        }
        return result;
    }
};