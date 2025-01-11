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
    int expected;
    fin >> input >> expected;

    vector<int> values;
    regex patternNumber("\\d+");
    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        values.emplace_back(stoi(*itr));
    }

    cout << input << ": values" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.maxScoreSightseeingPair(values) << ": actual" << endl;
    return 0;
}