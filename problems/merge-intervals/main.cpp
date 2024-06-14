#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>
using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"

void printResult(vector<vector<int>> intervals) {
    cout << "[";
    for (int i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1) cout << ",";
    }
    cout << "]: actual" << endl;
}

int main(int argc, char** argv) {
    Solution s;
    Solution2 soln2;
    regex patternNumber("\\d+");
    string line;
    ifstream fin(argv[1]);

    while (!fin.eof()) {
        vector<vector<int>> intervals;
        getline(fin, line);
        cout << line << " : input" << endl;
        for (sregex_token_iterator itr(line.begin(), line.end(), patternNumber); itr != sregex_token_iterator(); itr++) {
            vector<int> interval;
            interval.push_back(atoi((*itr).str().c_str()));
            itr++;
            interval.push_back(atoi((*itr).str().c_str()));
            intervals.push_back(interval);
        }
        vector<vector<int>> res1 = s.merge(intervals);
        printResult(res1);
        vector<vector<int>> res2 = soln2.merge(intervals);
        printResult(res2);
        cout << endl;
    }
    return 0;
}