#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    int a, b, c;
    string expected;
    fin >> a >> b >> c >> expected;
    if (a < 0 || a > 100 || b < 0 || b > 100 || c < 0 || c > 100) {
        cout << "Error: a, b and c have to be between 0 and 100, inclusive." << endl;
        exit(1);
    }
    if (a + b + c == 0) {
        cout << "Error: a, b and c cannot all be 0s." << endl;
        exit(1);
    }
    cout << a << ": a" << endl;
    cout << b << ": b" << endl;
    cout << c << ": c" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.longestDiverseString(a, b, c) << ": actual" << endl;
    return 0;
}
