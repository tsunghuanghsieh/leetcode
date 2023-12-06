#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#include "Solution.cpp"

using namespace std;

// Validation
void printNums(vector<int> nums) {
    cout << " ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    vector<int> nums;
    int x, expected;
    regex patternNumber("\\d+");
    string input;
    fstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    fin >> input >> x >> expected;
    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(atoi((*itr).str().c_str()));
    }
    cout << input << ": input" << endl;
    printNums(nums);
    cout << x << ": x" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.minOperations(nums, x) << ": actual (Solution)" << endl;
    return 0;
}