#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printAccounts(vector<vector<string>> accounts) {
    cout << "[";
    for (int i = 0; i < accounts.size(); i++) {
        cout << "[";
        for (int j = 0; j < accounts[i].size(); j++) {
            cout << "\"" << accounts[i][j] << "\"";
            if (j + 1 < accounts[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < accounts.size()) cout << ",";
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
    string input, expected;
    fin >> input >> expected;
    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;

    vector<vector<string>> accounts;

    regex patternAccount("\\[[\"\\w,@\\.]+\\]");
    regex patternNoComaDblQuote("[^,\"]+");
    sregex_token_iterator itr(input.begin(), input.end(), patternAccount);
    for (; itr != sregex_token_iterator(); itr++) {
        string acct = *itr;
        acct = acct.substr(1, acct.size() - 2);
        sregex_token_iterator itr_field(acct.begin(), acct.end(), patternNoComaDblQuote);
        vector<string> account = {itr_field, sregex_token_iterator()};
        accounts.emplace_back(account);
    }
    printAccounts(soln.accountsMerge(accounts));
    return 0;
}