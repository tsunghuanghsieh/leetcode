#include <fstream>
#include <iostream>
#include <math.h>
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
    regex patternRow("\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternRow);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.push_back(stoi(*itr));
        if (nums.back() > pow(10, 3)) {
            cout << "ERROR: array element value is too big." << endl;
            exit(1);
        }
    }

    if (0 == nums.size() || nums.size() > pow(10, 3)) {
        cout << "ERROR: array length violation." << endl;
        exit(1);
    }

    if (k == 0 || k > pow(10, 3) || k > nums.size()) {
        cout << "ERROR: k value violation." << endl;
        exit(1);
    }

    cout << line << ": input" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.minimumDifference(nums, k) << ": actual" << endl;
    return 0;
}
