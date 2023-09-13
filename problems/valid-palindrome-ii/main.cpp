#include <fstream>
#include <iostream>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);

    string s;
    fin >> s;
    cout << soln.validPalindrome(s) << endl;
    return 0;
}