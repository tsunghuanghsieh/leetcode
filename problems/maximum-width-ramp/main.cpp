#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string line;
    int expected;
    fin >> line >> expected;

    vector<int> nums;
    regex patternNums("\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternNums);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.push_back(stoi(*itr));
    }
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.maxWidthRamp(nums) << ": actual" << endl;
    return 0;
}
