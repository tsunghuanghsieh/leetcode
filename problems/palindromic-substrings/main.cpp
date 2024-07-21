#include <fstream>
#include <iostream>

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
    string s;
    int expected;
    fin >> s >> expected;
    cout << s << ": s" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.countSubstrings(s) << ": actual" << endl;
    return 0;
}