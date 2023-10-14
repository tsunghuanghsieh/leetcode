#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    string input, expected, result;
    ifstream fin(argv[1]);
    fin >> input >> expected;
    cout << input << " : input" << endl;
    cout << expected << " : expected" << endl;
    result = soln.minRemoveToMakeValid(input);
    cout << result << " : actual" << endl;

    return 0;
}