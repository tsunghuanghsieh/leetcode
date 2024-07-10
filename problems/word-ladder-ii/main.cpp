#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <unordered_map>

using namespace std;

#include "Solution.cpp"

void printResult(vector<vector<string>> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]: actual" << endl;
}

int main(int argc, char** argv) {
    vector<string> wordList;
    Solution s;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    string beginWord, endWord, line, expected;
    fin >> beginWord >> endWord >> line >> expected;

    regex patternWord("\\w+");
    sregex_token_iterator itr(line.begin(), line.end(), patternWord);
    for (; itr != sregex_token_iterator(); itr++) wordList.push_back(*itr);

    cout << beginWord << ": beginWord" << endl;
    cout << endWord << ": endWord" << endl;
    cout << line << ": wordList" << endl;
    cout << expected << ": expected" << endl;
    printResult(s.findLadders(beginWord, endWord, wordList));
    return 0;
}