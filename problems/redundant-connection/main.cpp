#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printEdges(vector<vector<int>> edges) {
    for (int e = 0; e < edges.size(); e++) {
        for (int v = 0; v < edges[e].size(); v++) {
            cout << edges[e][v] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string input, expected;
    fin >> input >> expected;

    regex patternEdge(R"((\d+),(\d+))");
    sregex_iterator itrEdge(input.begin(), input.end(), patternEdge);
    vector<vector<int>> edges;
    for (; itrEdge != sregex_iterator(); itrEdge++) {
        vector<int> edge;
        edge.emplace_back(stoi((*itrEdge)[1]));
        edge.emplace_back(stoi((*itrEdge)[2]));
        edges.emplace_back(edge);
    }

    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;
    vector<int> edge = soln.findRedundantConnection(edges);
    cout << "[" << edge[0] << "," << edge[1] << "]: actual" << endl;
}
