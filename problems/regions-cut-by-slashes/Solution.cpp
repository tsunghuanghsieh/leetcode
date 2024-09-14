#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // My approach is to treat the grid as a graph with vertices, enumerate the grid to find forward and
    // backward slashes (a slash has 2 vertices) and use dfs for each encountered pair of vertice to find
    // disjoint sets (2 boundary vertices or vertices that forms a loop) while keeping track of visited
    // vertices.
    int regionsBySlashes(vector<string>& grid) {
    }
};
