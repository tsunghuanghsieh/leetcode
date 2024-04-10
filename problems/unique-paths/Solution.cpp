#include <iostream>
#include <vector>

using namespace std;

// BFS
// say m = 4, n = 3
// 1  1  1  1
// 1  2  3  4
// 1  3  6 10
// At each position, the number is the sum of unique paths that robot can take to reach from the 2 possible positions.
//
// DFS is the inverse
// 10  6  3  1
//  4  3  2  1
//  1  1  1  1
class Solution {
public:
    // BFS
    int uniquePaths(int m, int n) {
        vector<int> paths(m, 1);

        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                paths[i] += paths[i - 1];
            }
        }
        return paths[m - 1];
    }
};
