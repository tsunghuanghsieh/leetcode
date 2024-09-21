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
    regex patternRow("-?\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternRow);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.push_back(stoi(*itr));
    }

    cout << line << ": nums" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.maximumSubarraySum(nums, k) << ": actual" << endl;
    return 0;

}