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

    int k;
    string input, expected;
    fin >> input >> k >> expected;

    regex patternNumber("-?\\d+");
    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    // a different way of initialize vector variable using accumulate and lambda function
    // have been using a separate loop to populate vector before this
    vector<int> nums(accumulate(itr, sregex_token_iterator(), vector<int>(), [](vector<int> initial, sregex_token_iterator::value_type s) {
        initial.emplace_back(stoi(s));
        return initial;
    }));

    cout << input << ": input" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    printResult(soln.topKFrequent(nums, k));
    return 0;
}