#include <iostream>
#include <fstream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char** argv) {
    Solution s;
    string line;
    int expected;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    fin >> line >> expected;
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << s.numDecodings(line) << ": actual" << endl;
    return 0;
}