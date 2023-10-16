#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    int n, index, maxSum, expected, maximized;
    fin.open(argv[1]);
    fin >> n >> index >> maxSum >> expected;
    cout << "array size n " << n << endl;
    cout << "index " << index << endl;
    cout << "maxSum " << maxSum << endl;
    cout << "expected maximized " << expected << endl;
    maximized = soln.maxValue(n, index, maxSum);
    cout << "actual maximized " << maximized << endl;
    return 0;
}
