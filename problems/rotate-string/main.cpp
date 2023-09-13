#include <fstream>
#include <iostream>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);

    string s, goal;
    fin >> s >> goal;
    if (s.size() == 0 || s.size() > 100 || goal.size() == 0 || goal.size() > 100) {
        // constraint #1
        cout << "The length of input strings has to be between 1 and 100, inclusive.";
        return -1;
    }
    for (char c : s) {
        // constraint #2
        if (!isalpha(c)) {
            cout << "First input string must consist of values from a to z only.";
        }
    }
    for (char c : goal) {
        // constraint #2
        if (!isalpha(c)) {
            cout << "Second input string must consist of values from a to z only.";
        }
    }
    cout << soln.rotateString(s, goal) << endl;
    return 0;
}