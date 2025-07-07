#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char** argv) {
    Solution soln;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    int x, y, expected;
    fin >> x >> y >> expected;

    cout << x << ": x" << endl;
    cout << y << ": y" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.minKnightMoves(x, y) << ": actual" << endl;
    return 0;
}