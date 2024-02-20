#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    fstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    string path, expected;
    fin >> path >> expected;

    cout << path << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.simplifyPath(path) << ": actual" << endl;
    return 0;
}