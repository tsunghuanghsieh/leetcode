#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    Solution soln;
    bool result = false;
    string input;
    ifstream fin;
    fin.open(argv[1]);

    fin >> input;
    result = soln.isValid(input);
    cout << result << endl;

    return 0;
}