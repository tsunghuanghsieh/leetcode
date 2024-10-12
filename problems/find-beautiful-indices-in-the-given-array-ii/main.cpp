#include <fstream>
#include <iostream>
#include <math.h>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(vector<int> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]: actual" << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    string s, a, b, expected;
    int k;
    fin >> s >> a >> b >> k >> expected;


    cout << s << ": s" << endl;
    cout << a << ": a" << endl;
    cout << b << ": b" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    printResult(soln.beautifulIndices(s, a, b, k));
    return 0;
}
