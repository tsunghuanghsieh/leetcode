#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string word1, word2, expected;
    fin >> word1 >> word2 >> expected;

    cout << word1 << ": word1" << endl;
    cout << word2 << ": word2" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.mergeAlternately(word1, word2) << ": actual" << endl;
    return 0;
}