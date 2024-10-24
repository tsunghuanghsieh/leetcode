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

    string s1, s2;
    int expected;
    fin >> s1 >> s2 >> expected;

    cout << s1 << ": s1" << endl;
    cout << s2 << ": s2" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.checkInclusion(s1, s2) << ": actual" << endl;
    return 0;
}
