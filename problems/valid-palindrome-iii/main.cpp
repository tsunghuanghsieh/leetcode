#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"

int main(int argc, char **argv) {
    Solution soln;
    Solution2 soln2;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string s;
    int k;
    bool expected;
    fin >> s >> k >> expected;

    cout << s << ": s" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.isValidPalindrome(s, k) << ": actual soln" << endl;
    cout << soln2.isValidPalindrome(s, k) << ": actual soln2" << endl;
    return 0;
}
