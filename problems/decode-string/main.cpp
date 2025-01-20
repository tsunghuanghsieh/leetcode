#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

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
    string s, expected;
    fin >> s >> expected;

    cout << s << ": s" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.decodeString(s) << ": actual" << endl;
    return 0;
}
