#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution s;
    int m, n, expected;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    fin >> m >> n >> expected;
    cout << "m = " << m << " n = " << n << endl;
    cout << expected << ": expected" << endl;
    cout << s.uniquePaths(m, n) << ": actual" << endl;
    return 0;
}