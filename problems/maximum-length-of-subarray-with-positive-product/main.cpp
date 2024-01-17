#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    regex patternNumber("-?\\d+");
    string input;
    int expected;
    vector<int> nums;
    ifstream fin;

    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    fin >> input >> expected;
    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;

    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(atoi((*itr).str().c_str()));
    }
    cout << soln.getMaxLen(nums) << ": actual" << endl;
    return 0;
}