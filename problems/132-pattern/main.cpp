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
    cout << soln.find132pattern(nums) << ": actual" << endl;
    return 0;
}