#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <sstream>
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

    int n;
    string line, expected;
    fin >> n >> line >> expected;

    regex patternLog("\\d+:\\w+:\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternLog);
    // a different way of initialize vector variable using accumulate and lambda function
    // have been using a separate loop to populate vector before this
    vector<string> logs(accumulate(itr, sregex_token_iterator(), vector<string>(), [](vector<string> initial, sregex_token_iterator::value_type s) {
        initial.emplace_back(s);
        return initial;
    }));

    cout << n << ": n" << endl;
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    printResult(soln.exclusiveTime(n, logs));
    return 0;
}