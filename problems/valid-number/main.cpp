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
    string s;
    bool expected;
    fin >> s >> expected;

    cout << s << ": s" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.isNumber(s) << ": actual" << endl;
    return 0;
}
