#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char* argv[]) {
    Solution soln;
    fstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string s;
    int expected;
    fin >> s >> expected;
    cout << s << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.romanToInt(s) << ": actual" << endl;
    return 0;
}