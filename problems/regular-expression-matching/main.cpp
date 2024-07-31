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

    string s, p;
    bool expected;
    fin >> s >> p >> expected;

    cout << s << ": s" << endl;
    cout << p << ": p" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.isMatch(s, p) << ": actual" << endl;
    return 0;

}