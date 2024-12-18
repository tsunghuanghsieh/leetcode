#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution1.cpp"

int main(int argc, char **argv) {
    Solution soln;
    Solution1 soln1;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string input1, input2;
    int expected;
    fin >> input1 >> input2 >> expected;

    vector<int> nums;
    regex patternNumber("\\d+");
    sregex_token_iterator itrNums(input1.begin(), input1.end(), patternNumber);
    for (; itrNums != sregex_token_iterator(); itrNums++) {
        nums.emplace_back(stoi(*itrNums));
    }
    vector<vector<int>> queries;
    regex patternQuery("(\\d+),(\\d+),(\\d+)");
    sregex_iterator itrQueries(input2.begin(), input2.end(), patternQuery);
    for (; itrQueries != sregex_iterator(); itrQueries++) {
        vector<int> query = {stoi((*itrQueries)[1]), stoi((*itrQueries)[2]), stoi((*itrQueries)[3])};
        queries.emplace_back(query);
    }

    cout << ((input1.size() > 140) ?
        (input1.substr(0, 40) + "...(" +  to_string(nums.size()) + ")") : input1) << ": nums" << endl;
    cout << ((input2.size() > 140) ?
        (input2.substr(0, 40) + "...(" +  to_string(queries.size()) + ")") : input2) << ": queries" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.minZeroArray(nums, queries) << ": actual soln" << endl;
    cout << soln1.minZeroArray(nums, queries) << ": actual soln 1" << endl;
    return 0;
}