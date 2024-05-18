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
    cout << soln.minStickers(stickers, target) << ": actual" << endl;
    return 0;
}