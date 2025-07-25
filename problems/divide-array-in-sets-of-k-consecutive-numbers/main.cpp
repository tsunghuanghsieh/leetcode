#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"

int main(int argc, char** argv) {
    Solution soln;
    Solution2 soln2;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string line;
    int k, expected;
    fin >> line >> k >> expected;

    vector<int> nums;
    regex patternNumber(R"((\d+))");
    sregex_token_iterator itr(line.begin(), line.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(stoi(*itr));
    }

    cout << line << ": nums" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.isPossibleDivide(nums, k) << ": actual" << endl;
    cout << soln2.isPossibleDivide(nums, k) << ": actual soln2" << endl;
    return 0;
}