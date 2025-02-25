#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;

    ifstream fin(argv[1]);
    if (!fin) {
        cerr << "Error: could not open file " << argv[1] << endl;
        return 1;
    }

    string line;
    int expected;
    fin >> line >> expected;

    regex patternNumber("-?\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternNumber);
    vector<int> nums;
    for (; itr != sregex_token_iterator(); itr++) {
        nums.push_back(stoi(*itr));
    }
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.lengthOfLIS(nums) << ": actual" << endl;
    return 0;
}