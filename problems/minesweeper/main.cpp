#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

vector<vector<char>> createBoard(string input) {
    vector<vector<char>> board;
    regex patternRow(R"(\[("[MBE1-8]"(,"[MBE1-8]")*)\])");
    sregex_iterator itrRow(input.begin(), input.end(), patternRow);
    for (; itrRow != sregex_iterator(); itrRow++) {
        string row_str = (*itrRow)[0];
        vector<char> row;
        regex patternCol(R"([MBE1-8])");
        sregex_iterator itrCol(row_str.begin(), row_str.end(), patternCol);
        for (; itrCol != sregex_iterator(); itrCol++) {
            string col_str = (*itrCol)[0];
            row.emplace_back(*col_str.c_str());
        }
        board.emplace_back(row);
    }
    return board;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    string line_board, line_click, line_expected;
    fin >> line_board >> line_click >> line_expected;

    vector<vector<char>> board = createBoard(line_board);
    vector<vector<char>> expected = createBoard(line_expected);
    vector<int> click;
    regex patternClick(R"([0-9])");
    sregex_iterator itrClick(line_click.begin(), line_click.end(), patternClick);
    for (; itrClick != sregex_iterator(); itrClick++) {
         click.emplace_back(stoi((*itrClick)[0]));
    }

    cout << line_board << ": board" << endl;
    cout << line_click << ": click" << endl;
    cout << line_expected << ": expected" << endl;

    vector<vector<char>> result = soln.updateBoard(board, click);
    cout << "expected board" << endl;
    Solution::printBoard(expected);
    cout << "actual board" << endl;
    Solution::printBoard(result);
}
