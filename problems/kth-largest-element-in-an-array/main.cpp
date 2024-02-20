#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    string line;
    vector<int> nums;
    int k, expected;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    getline(fin, line);
    regex patternNum("-?\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternNum);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(atoi((*itr).str().c_str()));
    }
    fin >> k >> expected;
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.findKthLargest(nums, k) << ": actual" << endl;
    return 0;
}