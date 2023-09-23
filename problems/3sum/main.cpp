#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "Solution.cpp"

using namespace std;

void printResult(vector<vector<int>> results) {
    for (vector<int> triplet : results) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    regex patternInt("[-|+]?\\d+");
    string line;
    fstream fin;
    fin.open(argv[1]);

    while (getline(fin, line)) {
        cout << line << endl;
        vector<int> tc;
        for (sregex_token_iterator itr(line.begin(), line.end(), patternInt); itr != sregex_token_iterator(); itr++) {
            tc.emplace_back(atoi((*itr).str().c_str()));
        }
        vector<vector<int>> results = soln.threeSum(tc);
        printResult(results);
    }
    return 0;
}