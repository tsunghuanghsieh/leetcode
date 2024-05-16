#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    fstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string line;
    int k, expected;
    fin >> line >> k >> expected;
    regex patternNumber("-?\\d+");
    vector<int> nums;
    sregex_token_iterator itr(line.begin(), line.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.push_back(stoi((*itr).str()));
    }
    cout << line << ": input" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.subarraySum(nums, k) << ": actual" << endl;
    return 0;
}