#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"

int main(int argc, char **argv)
{
    Solution soln;
    Solution2 soln2;

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
    string res = soln.minWindow(s, t);
    cout << ((res.size() > 10000) ? (res == expected) ? "identical" : "different" : res) << ": actual (Mine)" << endl;
    string res2 = soln2.minWindow(s, t);
    cout << ((res2.size() > 10000) ? (res2 == expected) ? "identical" : "different" : res2) << ": actual (LC)" << endl;
    return 0;
}
