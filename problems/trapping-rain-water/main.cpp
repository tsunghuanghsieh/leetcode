#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution s;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line;
    int expected;
    fin >> line >> expected;

    vector<int> height;
    regex pattternNum("\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), pattternNum);
    for (; itr != sregex_token_iterator(); itr++) height.emplace_back(stoi(*itr));

    cout << line << ": line" << endl;
    cout << expected << ": expected" << endl;
    cout << s.trap(height) << ": actual" << endl;
    return 0;
}