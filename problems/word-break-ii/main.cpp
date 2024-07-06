#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(vector<string> res) {
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "\"" << res[i] << "\"";
        if (i + 1 < res.size()) cout << ",";
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
    string line1, line2, expected;
    fin >> line1 >> line2;
    fin.get();   // eat newline character
    getline(fin, expected);
    vector<string> wordDict;
    regex patternWord("\\w+");
    sregex_token_iterator itr(line2.begin(), line2.end(), patternWord);
    for (; itr != sregex_token_iterator(); itr++) wordDict.emplace_back(*itr);

    cout << line1 << ": line" << endl;
    cout << line2 << ": wordDict" << endl;
    cout << expected << ": expected" << endl;
    printResult(soln.wordBreak(line1, wordDict));
    return 0;
}
