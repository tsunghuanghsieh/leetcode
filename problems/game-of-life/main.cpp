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

vector<vector<int>> createBoard(string line) {
    regex patternRow("\\[(0|1)(,(0|1))*\\]");
    regex patternCol("0|1");
    vector<vector<int>> board;
    sregex_token_iterator itrRow(line.begin(), line.end(), patternRow);
    for (; itrRow != sregex_token_iterator(); itrRow++) {
        string row((*itrRow).str());
        sregex_token_iterator itrCol(row.begin(), row.end(), patternCol);
        vector<int> cols;
        for (; itrCol != sregex_token_iterator(); itrCol++) {
            cols.push_back(stoi((*itrCol).str()));
        }
        board.push_back(cols);
    }
    return board;
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
    string line1, line2;
    fin >> line1 >> line2;
    vector<vector<int>> board = createBoard(line1);
    vector<vector<int>> expected = createBoard(line2);

    cout << line1 << ": input" << endl;
    cout << line2 << ": expected" << endl;
    cout << "input" << endl;
    printGrid(board);
    soln.gameOfLife(board);
    cout << "result" << endl;
    printGrid(board);
    cout << "expected" << endl;
    printGrid(expected);

    return 0;
}
