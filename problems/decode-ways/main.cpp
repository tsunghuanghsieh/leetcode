#include <iostream>
#include <fstream>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"
#include "Solution3.cpp"

int main(int argc, char** argv) {
    Solution s;
    Solution2 s2;
    Solution3 s3;
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
    cout << s.numDecodings(line) << ": actual (Fibonacci)" << endl;
    cout << s2.numDecodings(line) << ": actual (DP iterative)" << endl;
    cout << s3.numDecodings(line) << ": actual (DP recursive)" << endl;
    return 0;
}