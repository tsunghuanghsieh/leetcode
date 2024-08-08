#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv)
{
    Solution soln;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line, expected;
    fin >> line >> expected;

    vector<int> ages;
    regex patternNumber("\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) ages.push_back(stoi(*itr));

    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.numFriendRequests(ages) << ": actual" << endl;
    return 0;
}
