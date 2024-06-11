#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv)
{
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    int num, expected;
    fin >> num >> expected;

    cout << num << ": input" << endl;
    cout << expected << ": result" << endl;
    cout << soln.maximumSwap(num) << ": actual" << endl;
    return 0;
}
