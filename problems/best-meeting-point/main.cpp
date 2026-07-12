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
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string line;
    int expected;
    fin >> line >> expected;

    int count1s = 0;
    vector<vector<int>> grid;
    regex patternRow("[10](,[10])*|\\[\\]");
    regex patternCell("[10]");
    sregex_iterator itrRow(line.begin(), line.end(), patternRow);
    for (; itrRow != sregex_iterator(); itrRow++) {
        string row = (*itrRow)[0];
        vector<int> vrow;
        sregex_token_iterator itrCell(row.begin(), row.end(), patternCell);
        for (; itrCell != sregex_token_iterator(); itrCell++) {
            if (stoi((*itrCell)) == 1) count1s++;
            vrow.emplace_back(stoi((*itrCell)));
        }
        if (vrow.size() == 0 || vrow.size() > 200) {
            // constraint violation check
            cout << "ERROR: " << argv[1] << " violates constraint, 1 <= column <= 200." << endl;
            exit(1);
        }
        grid.emplace_back(vrow);
    }
    if (grid.size() == 0 || grid.size() > 200) {
        // constraint violation check
        cout << "ERROR: " << argv[1] << " violates constraint, 1 <= row <= 200." << endl;
        exit(1);
    }
    if (count1s < 2) {
        // constraint violation check
        cout << "ERROR: " << argv[1] << " contains less than 2 friends." << endl;
        exit(1);
    }
    vector<vector<int>> grid2(grid);
    cout << line << ": line" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.minTotalDistance(grid) << ": actual soln" << endl;
    cout << soln2.minTotalDistance(grid2) << ": actual soln2" << endl;

    return 0;
}