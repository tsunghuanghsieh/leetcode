#include <fstream>
#include <iostream>
#include <string>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);

    string s;
    getline(fin, s);
    int result = soln.myAtoi(s);
    cout << "result is " << result << endl;
    return 0;
}