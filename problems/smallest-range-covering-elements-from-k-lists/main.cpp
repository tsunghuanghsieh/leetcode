#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(vector<int> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
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

    vector<vector<int>> nums;
    regex patternNumList("\\[-?\\d+(,-?\\d+)*\\]");
    regex patternNumber("-?\\d+");
    sregex_token_iterator itrList(input.begin(), input.end(), patternNumList);
    for (; itrList != sregex_token_iterator(); itrList++) {
        string sNumList = *itrList;
        vector<int> list;
        sregex_token_iterator itrNums(sNumList.begin(), sNumList.end(), patternNumber);
        for (; itrNums != sregex_token_iterator(); itrNums++) {
            list.emplace_back(stoi(*itrNums));
        }
        nums.emplace_back(list);
    }

    cout << input << ": nums" << endl;
    cout << expected << ": expected" << endl;
    printResult(soln.smallestRange(nums));
    return 0;
}