#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution1.cpp"

int main(int argc, char **argv) {
    Solution soln;
    Solution_dp soln_dp;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line1, target;
    int expected;
    fin >> line1 >> target >> expected;

    vector<string> stickers;
    regex patternString("\\w+");
    sregex_token_iterator itr(line1.begin(), line1.end(), patternString);
    for (; itr != sregex_token_iterator(); itr++) stickers.emplace_back(*itr);

    cout << line1 << ": stickers" << endl;
    cout << target << ": target" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.minStickers(stickers, target) << ": actual (brute force)" << endl;
    cout << soln_dp.minStickers(stickers, target) << ": actual (dp)" << endl;
    return 0;
}