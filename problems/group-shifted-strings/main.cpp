#include <fstream>
#include <iostream>
#include <regex>
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
    cout << "] : actual" << endl;
}

int main(int argc, char **argv)
{
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string input, expected;
    fin >> input >> expected;

    regex patternCmd("\\w+");
    vector<string> strings;
    sregex_token_iterator itr_cmd(input.begin(), input.end(), patternCmd);
    for (int i = 0; itr_cmd != sregex_token_iterator(); i++, itr_cmd++) {
        strings.emplace_back((*itr_cmd).str());
    }

    cout << input << ": input" << endl;
    cout << expected << ": possible result" << endl;
    printResult(soln.groupStrings(strings));
    return 0;
}
