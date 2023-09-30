#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    int num;
    string output;
    ifstream fin;

    fin.open(argv[1]);
    fin >> num;
    fin >> output;

    string result = soln.countAndSay(num);
    cout << ((result.compare(output) == 0) ? "same" : "different") << endl;

    return 0;
}