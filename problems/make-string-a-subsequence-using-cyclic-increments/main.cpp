#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    string str1, str2;
    bool expected;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    fin >> str1 >> str2 >> expected;
    cout << str1 << ": str1" << endl;
    cout << str2 << ": str2" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.canMakeSubsequence(str1, str2) << ": actual" << endl;

    return 0;
}

