#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution s;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line;
    int expected;
    fin >> line >> expected;
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << s.minAddToMakeValid(line) << ": actual" << endl;
    return 0;
}