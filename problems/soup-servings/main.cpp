#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    int n;
    double expected, actual;
    fin.open(argv[1]);
    fin >> n >> expected;
    cout << setprecision(5) << std::fixed;
    cout << expected << " expected probability " << endl;
    actual = soln.soupServings(n);
    cout << actual << " actual probability " << endl;
    return 0;
}
