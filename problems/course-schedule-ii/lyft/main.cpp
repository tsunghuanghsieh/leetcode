#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char** argv) {
    Solution s;
    map<int, vector<int>> input;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    int count, index;
    string data, expected;
    regex patternNumber("\\d+");
    fin >> count;
    for (int i = 0; i < count; i++) {
        fin >> index >> data;
        sregex_token_iterator itr(data.begin(), data.end(), patternNumber);
        vector<int> vals;
        for (; itr != sregex_token_iterator(); itr++) {
            vals.push_back(atoi((*itr).str().c_str()));
        }
        input[index] = vals;
    }
    s.printInput(input);
    fin >> expected;
    cout << expected << ": expected" << endl;

    vector<int> linearization = s.sortTopological(input);
    cout << "[";
    for (int i = 0; i < linearization.size(); i++) {
        cout << linearization[i];
        if (i + 1 < linearization.size()) cout << ",";
    }
    cout << "]: actual" << endl;
    return 0;
}