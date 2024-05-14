#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution s;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string order, input, expected;
    fin >> order >> input >> expected;
    cout << order << ": order" << endl;
    cout << input << ": s" << endl;
    cout << expected << ": expected" << endl;
    cout << s.customSortString(order, input) << ": actual" << endl;
    return 0;
}