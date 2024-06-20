#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printMatrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printVector(vector<int> res) {
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]: actual" << endl;
}
int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string input, expected;
    fin >> input >> expected;

    vector<vector<int>> matrix;
    regex patternRow("\\d+(,\\d+)*");
    regex patternCol("\\d+");
    sregex_token_iterator itrR(input.begin(), input.end(), patternRow);
    for (; itrR != sregex_token_iterator(); itrR++) {
        vector<int> vrow;
        string row = *itrR;
        // cout << row << endl;
        sregex_token_iterator itrC(row.begin(), row.end(), patternCol);
        for (; itrC != sregex_token_iterator(); itrC++) {
            // cout << (*itrC).str() << " ";
            vrow.emplace_back(stoi((*itrC).str()));
        }
        // cout << endl;
        matrix.emplace_back(vrow);
        // cout << "matrix.size() " << matrix.size() << endl;
        // printVector(vrow);
    }
        // cout << "matrix.size() " << matrix.size() << endl;

    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;
    printMatrix(matrix);
    printVector(soln.findDiagonalOrder(matrix));
    return 0;
}