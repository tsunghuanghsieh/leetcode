#include <fstream>
#include <iostream>
#include <string>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    string s, t;
    fin >> s >> t;
    cout << "s " << s << " t " << t << endl;
    cout << soln.isAnagram(s, t) << endl;
    return 0;
}