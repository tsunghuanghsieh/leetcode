#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv)
{
    Solution soln;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string s, t, expected;
    fin >> s >> t >> expected;

    cout << s << ": s" << endl;
    cout << t << ": t" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.minWindow(s, t) << ": actual" << endl;
    return 0;
}
