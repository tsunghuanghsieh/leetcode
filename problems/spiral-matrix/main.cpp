#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

#include "Solution.cpp"

void printMatrix(vector<vector<int>> matrix) {
    cout << "[";
    for (int i = 0; i < matrix.size(); i++) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

void printResult(vector<int> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]";
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    regex patternRow("-?\\d+(,-?\\d+)*");
    regex patternNum("-?\\d+");
    string line;
    string expected;
    vector<vector<int>> matrix;

    fin.open(argv[1]);
    getline(fin, line);
    cout << line << " : input" << endl;
    for (sregex_token_iterator itr(line.begin(), line.end(), patternRow); itr != sregex_token_iterator(); itr++) {
        string row = *itr;
        vector<int> nums;
        for (sregex_token_iterator itr_digit(row.begin(), row.end(), patternNum); itr_digit != sregex_token_iterator(); itr_digit++) {
            nums.push_back(atoi((*itr_digit).str().c_str()));
        }
        matrix.push_back(nums);
    }
    printMatrix(matrix);
    fin >> expected;
    cout << expected << " : expected" << endl;
    printResult(soln.spiralOrder(matrix));
    cout <<  " : actual" << endl;

    return 0;
}