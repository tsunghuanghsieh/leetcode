#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // My approach is to treat the grid as a directed graph with vertices. Each forward and backward slash
    // has 2 vertices and each vertex has 4 possible directed edges which have a unique value (see below for
    // illustration). It enumerates through the vertices and use dfs for each encountered vertex to group
    // all connected vertices. From the disjoint sets of vertices, it will then determine the total number
    // of regions.
    // 4  1  ----
    //  \/   | /|   0 0 2
    //  /\   | \|   0 9 0
    // 2  8  ----   0 0 4
    //
    // LC Editorial soln 1 gives an idea to expand the grid by 3x (2x is too small and will cause confusion)
    // and line of the slashes will be marked as 1 while empty space is 0. In doing so, we can just count the
    // number of region 0s.
    //
    //  /\    0  0  1  1  0  0
    //  \/    0  1  0  0  1  0
    //        1  0  0  0  0  1
    //        0  1  0  0  1  0
    //        0  0  1  1  0  0
    //
    int regionsBySlashes(vector<string>& grid) {
    }
};
