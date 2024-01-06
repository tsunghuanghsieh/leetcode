#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    string input, expected, actual;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    fin >> input >> expected;
    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.reorganizeString(input) << ": actual" << endl;
    return 0;
}