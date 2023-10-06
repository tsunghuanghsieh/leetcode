#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    regex patternNum("\\d+");
    string line;
    bool expected;
    vector<int> nums;

    fin.open(argv[1]);
    getline(fin, line);
    cout << line << " : input" << endl;
    for (sregex_token_iterator itr(line.begin(), line.end(), patternNum); itr != sregex_token_iterator(); itr++) {
        string row = *itr;
        nums.push_back(atoi((*itr).str().c_str()));
    }
    fin >> expected;
    cout << expected << " : expected" << endl;
    cout << ((soln.canJump(nums) == expected) ? "correct" : "wrong") << endl;

    return 0;
}