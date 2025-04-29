#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line, chars;
    int expected;
    fin >> line >> chars >> expected;

    regex patternWord("[a-z]+");
    sregex_token_iterator itrWord(line.begin(), line.end(), patternWord);
    vector<string> words;
    for (; itrWord != sregex_token_iterator(); itrWord++) {
        words.push_back(*itrWord);
    }
    cout << line << ": words" << endl;
    cout << chars << ": chars" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.countCharacters(words, chars) << ": actual" << endl;
    return 0;
}