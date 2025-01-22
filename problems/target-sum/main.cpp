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
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string input;
    int target, expected;
    fin >> input >> target >> expected;

    vector<int> nums;
    regex patternNumber("\\d+");
    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(stoi(*itr));
    }
    cout << input << ": nums" << endl;
    cout << target << ": target" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.findTargetSumWays(nums, target) << ": actual" << endl;
    return 0;
}
