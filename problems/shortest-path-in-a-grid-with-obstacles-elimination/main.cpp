#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"

int main(int argc, char **argv) {
    Solution soln;
    Solution2 soln2;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string line;
    int k, expected;
    fin >> line >> k >> expected;

    vector<vector<int>> grid;
    regex patternRow("\\[(0|1)(,(0|1))*\\]");
    regex patternCol("0|1");
    sregex_token_iterator itrRow(line.begin(), line.end(), patternRow);
    for (; itrRow != sregex_token_iterator(); itrRow++) {
        vector<int> columns;
        string row((*itrRow).str());
        sregex_token_iterator itrCol(row.begin(), row.end(), patternCol);
        for (; itrCol != sregex_token_iterator(); itrCol++) {
            columns.emplace_back(stoi(*itrCol));
        }
        grid.emplace_back(columns);
    }

    cout << line << ": grid" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.shortestPath(grid, k) << ": actual" << endl;
    cout << soln2.shortestPath(grid, k) << ": actual soln 2" << endl;
    return 0;
}