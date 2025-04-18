#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printGrid(vector<vector<int>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line;
    int expected;
    fin >> line >> expected;

    regex patternRow("\\[(0|1)(,(0|1))*\\]");
    regex patternCol("0|1");
    vector<vector<int>> isConnected;
    sregex_token_iterator itrRow(line.begin(), line.end(), patternRow);
    for (; itrRow != sregex_token_iterator(); itrRow++) {
        string row((*itrRow).str());
        sregex_token_iterator itrCol(row.begin(), row.end(), patternCol);
        vector<int> cols;
        for (; itrCol != sregex_token_iterator(); itrCol++) {
            cols.push_back(stoi((*itrCol).str()));
        }
        isConnected.push_back(cols);
    }
    cout << line << ": input" << endl;
    printGrid(isConnected);
    cout << expected << ": expected" << endl;
    cout << soln.findCircleNum(isConnected) << ": actual" << endl;
    return 0;
}
