#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char** argv) {
    Solution soln;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string line;
    int expected;
    fin >> line >> expected;

    vector<vector<char>> board;
    string regexStr = R"(["]([1-9.])["])";
    for (int i = 0; i < 8; i++) regexStr += R"(,["]([1-9.])["])";
    regex patternRow(regexStr);
    sregex_iterator itr(line.begin(), line.end(), patternRow);
    for (; itr != sregex_iterator(); itr++) {
        vector<char> row;
        for (int col = 1; col <= 9; col++) {
            row.emplace_back(*(((*itr)[col]).str().c_str()));
        }
        board.emplace_back(row);
    }

    cout << line << ": board" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.isValidSudoku(board) << ": actual" << endl;
    return 0;
}
