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
    int expected;
    getline(fin, line);
    fin >> expected;

    vector<string> grid;
    regex patternRow("[ /\\\\]+");
    regex patternChar("[ /\\\\]");
    sregex_token_iterator itrRow(line.begin(), line.end(), patternRow);
    for (; itrRow != sregex_token_iterator(); itrRow++) {
        string row = *itrRow;
        sregex_token_iterator itrChar(row.begin(), row.end(), patternChar);
        string s;
        for (int cnt = 0; itrChar != sregex_token_iterator(); itrChar++) {
            if (cnt % 2 == 0) s += *itrChar;
            // Backslashes in LC input are escaped. Hence '\' is represented as '\\'.
            // However, in `grid` passed into regionsBySlashes(), there is only 1 backslash.
            // We need to eat the 2nd backslash in the input file so that we can use LC input
            // as is in the test cases.
            if (*itrChar == '\\') cnt++;
        }
        grid.push_back(s);
    }

    cout << line << ": grid" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.regionsBySlashes(grid) << ": actual" << endl;
    return 0;

}