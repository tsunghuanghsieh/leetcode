#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printQueries(vector<vector<int>> queries) {
    for (int i = 0; i < queries.size(); i++) {
        cout << "[" << queries[i][0] << "," << queries[i][1] << "]" << endl;
    }
}

string actual_to_string(vector<int> actual) {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < actual.size(); i++) {
        ss << to_string(actual[i]);
        if (i + 1 < actual.size()) ss << ',';
    }
    ss << "]";
    return ss.str();
}

int main(int argc, char **argv) {
    Solution soln;
    string s, sQueries, expected;
    vector<vector<int>> queries;
    regex patternNumber("\\d+");
    regex patternNumberPair("\\d+,\\d+");
    fstream fin;
    fin.open(argv[1]);
    fin >> s >> sQueries >> expected;
    cout << s << ": string" << endl;
    cout << sQueries << ": queries" << endl;
    cout << expected << ": expected" << endl;
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    sregex_token_iterator itrPair(sQueries.begin(), sQueries.end(), patternNumberPair);
    for (; itrPair != sregex_token_iterator(); itrPair++) {
        sregex_token_iterator itrNum((*itrPair).str().begin(), (*itrPair).str().end(), patternNumber);
        queries.emplace_back(vector<int>{atoi((*itrNum).str().c_str()), atoi((*(++itrNum)).str().c_str())});
    }
    vector<int> actual = soln.platesBetweenCandles(s, queries);
    cout << actual_to_string(actual) << ": actual" << endl;
    return 0;
}
