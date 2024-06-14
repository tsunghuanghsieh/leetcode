#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(vector<vector<string>> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    if (result.size() == 0) {
        cout << "[\"\"]";
    }
    cout << "]: actual" << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    regex rx_word("\\w+");
    string line;
    vector<string> strs;
    string expected;
    ifstream fin;

    fin.open(argv[1]);
    getline(fin, line);
    cout << line << " : input" << endl;
    for (sregex_token_iterator itr(line.begin(), line.end(), rx_word); itr != sregex_token_iterator(); itr++) {
        strs.push_back(*itr);
    }
    fin >> expected;
    cout << expected << " : expected" << endl;
    vector<vector<string>> result = soln.groupAnagrams(strs);
    printResult(result);

    return 0;
}