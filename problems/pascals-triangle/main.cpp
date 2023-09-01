#include <iostream>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main (int argc, char **argv) {
    Solution soln;
    int numRows;

    numRows = stoi(string(argv[1]));
    vector<vector<int>> result = soln.generate(numRows);

    for (vector<int> row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}