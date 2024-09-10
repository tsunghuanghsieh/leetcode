#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    string line;
    bool expected;
    getline(fin, line);
    fin >> expected;

    vector<string> grid;
    regex patternRow("[ /\\\\]+");
    sregex_token_iterator itr(line.begin(), line.end(), patternRow);
    for (; itr != sregex_token_iterator(); itr++) {
        grid.push_back(*itr);
    }

    cout << line << ": grid" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.regionsBySlashes(grid) << ": actual" << endl;
    return 0;

}