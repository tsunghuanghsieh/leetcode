#include <fstream>
#include <iostream>
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
    string input;
    int n, expected;
    fin >> input >> n >> expected;

    vector<vector<int>> logs;
    regex patternQuery("(\\d+),(\\d+),(\\d+)");
    sregex_iterator itrQueries(input.begin(), input.end(), patternQuery);
    for (; itrQueries != sregex_iterator(); itrQueries++) {
        vector<int> log = {stoi((*itrQueries)[1]), stoi((*itrQueries)[2]), stoi((*itrQueries)[3])};
        logs.emplace_back(log);
    }

    cout << ((input.size() > 140) ?
        (input.substr(0, 40) + "...(" +  to_string(logs.size()) + ")") : input) << ": logs" << endl;
    cout << n << ": n" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.earliestAcq(logs, n) << ": actual" << endl;
    return 0;
}