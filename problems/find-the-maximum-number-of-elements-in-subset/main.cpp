#include <fstream>
#include <iostream>
#include <math.h>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    string line;
    int expected;
    fin >> line >> expected;

    vector<int> target;
    regex patternRow("\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternRow);
    for (; itr != sregex_token_iterator(); itr++) {
        target.push_back(stoi(*itr));
        if (target.back() > pow(10, 9)) {
            cout << "ERROR: target element value is too big." << endl;
            exit(1);
        }
    }

    if (target.size() > pow(10, 5)) {
        cout << "ERROR: target length is too long." << endl;
        exit(1);
    }

    cout << line << ": target" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.maximumLength(target) << ": actual" << endl;
    return 0;
}
