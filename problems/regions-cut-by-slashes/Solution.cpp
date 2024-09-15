#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // My approach is to treat the grid as a graph with vertices, enumerate the grid to find forward and
    // backward slashes (a slash has 2 vertices) and use dfs for each encountered pair of vertice to find
    // disjoint sets (2 boundary vertices or vertices that forms a loop) while keeping track of visited
    // vertices.
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
