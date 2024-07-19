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
    string word, abbr;
    int expected;
    fin >> word >> abbr >> expected;
    cout << word << ": word" << endl;
    cout << abbr << ": abbr" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.validWordAbbreviation(word, abbr) << ": actual" << endl;
    return 0;
}