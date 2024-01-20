#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    regex patternDigit("\\d+");
    vector<int> arr;
    string input;
    int expected;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    fin >> input >> expected;
    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;

    sregex_token_iterator itr(input.begin(), input.end(), patternDigit);
    for (; itr != sregex_token_iterator(); itr++) {
        arr.emplace_back(atoi((*itr).str().c_str()));
    }

    cout << soln.maximumElementAfterDecrementingAndRearranging(arr) << ": actual" << endl;
    return 0;
}