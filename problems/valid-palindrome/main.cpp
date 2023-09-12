#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);

    string s;
    getline(fin, s);
    cout << soln.isPalindrome(s) << endl;
    return 0;
}