#include <fstream>
#include <iostream>
#include <queue>
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
    int expected;
    fin >> input >> expected;

    vector<int> nums;
    regex patternBinary("0|1");
    sregex_token_iterator itr(input.begin(), input.end(), patternBinary);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(stoi(*itr));
    }
    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.findMaxLength(nums) << ": actual" << endl;
    return 0;
}
