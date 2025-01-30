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

    vector<int> prices;
    regex patternNumber("\\d+");
    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        prices.emplace_back(stoi(*itr));
    }
    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.maxProfit(prices) << ": actual" << endl;
    return 0;
}
