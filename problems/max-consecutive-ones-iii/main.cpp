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
    string line;
    int k, expected;
    fin >> line >> k >> expected;

    vector<int> nums;
    regex patternBinary("(1|0)");
    sregex_token_iterator itr(line.begin(), line.end(), patternBinary);
    for (; itr != sregex_token_iterator(); itr++) nums.emplace_back(stoi(*itr));

    cout << line << ": line" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.longestOnes(nums, k) << ": actual" << endl;
    return 0;
}