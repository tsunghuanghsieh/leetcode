#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    int n;
    double x, expected, result;
    ifstream fin;

    fin.open(argv[1]);
    fin >> x >> n >> expected;
    cout << "x is " << x << endl << "n is " << n << endl;
    cout << setprecision(5) << std::fixed << expected << " : expected" << endl;
    cout << soln.myPow(x, n) << " : actual" << endl;

    return 0;
}