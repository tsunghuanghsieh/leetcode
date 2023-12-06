#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#include "Solution.cpp"
#include "Solution2.cpp"

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
    Solution2 soln2;
    vector<int> nums;
    regex patternNumber("(-)?\\d+");
    string input;
    bool expected;
    fstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    fin >> input >> expected;
    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(atoi((*itr).str().c_str()));
    }
    cout << input << ": input" << endl;
    printNums(nums);
    cout << expected << ": expected" << endl;
    cout << soln.find132pattern(nums) << ": actual (Solution)" << endl;
    cout << soln2.find132pattern(nums) << ": actual (Solution2)" << endl;
    return 0;
}