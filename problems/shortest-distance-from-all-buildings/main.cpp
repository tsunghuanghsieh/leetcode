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
    fin >> line >> expected;

    int count1s = 0;
    vector<vector<int>> grid;
    regex patternRow("[120](,[120])*|\\[\\]");
    regex patternCell("[120]");
    sregex_iterator itrRow(line.begin(), line.end(), patternRow);
    for (; itrRow != sregex_iterator(); itrRow++) {
        string row = (*itrRow)[0];
        vector<int> vrow;
        sregex_token_iterator itrCell(row.begin(), row.end(), patternCell);
        for (; itrCell != sregex_token_iterator(); itrCell++) {
            if (stoi((*itrCell)) == 1) count1s++;
            vrow.emplace_back(stoi((*itrCell)));
        }
        if (vrow.size() == 0 || vrow.size() > 50) {
            // constraint violation check
            cout << "ERROR: " << argv[1] << " violates constraint, 1 <= column <= 50." << endl;
            exit(1);
        }
        grid.emplace_back(vrow);
    }
    if (grid.size() == 0 || grid.size() > 50) {
        // constraint violation check
        cout << "ERROR: " << argv[1] << " violates constraint, 1 <= row <= 50." << endl;
        exit(1);
    }
    if (count1s == 0) {
        // constraint violation check
        cout << "ERROR: " << argv[1] << " does not contain any 1s." << endl;
        exit(1);
    }
    cout << line << ": line" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.shortestDistance(grid) << ": actual" << endl;

    return 0;
}