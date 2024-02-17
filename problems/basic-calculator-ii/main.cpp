#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    fstream fin;
    string s;
    int expected;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    getline(fin, s);
    fin >> expected;
    cout << s << ": input" << endl;
    cout << s.substr(1, s.size() - 2) << ": input (sanitized)" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.calculate(s.substr(1, s.size() - 2)) << ": actual" << endl;
    return 0;
}