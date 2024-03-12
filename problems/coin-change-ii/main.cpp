#include <fstream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    string line;
    int amount = 0, expected = 0;
    vector<int> coins;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    fin >> amount;
    fin.get(); // eat newline char
    getline(fin, line);
    fin >> expected;

    regex patternNum("\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternNum);
    for (; itr != sregex_token_iterator(); itr++) {
        coins.emplace_back(atoi((*itr).str().c_str()));
    }

    cout << amount << ": amount" << endl;
    cout << line << ": coins" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.change(amount, coins) << ": actual" << endl;
    return 0;
}