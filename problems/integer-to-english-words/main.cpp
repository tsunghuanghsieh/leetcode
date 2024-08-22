#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv)
{
    Solution soln;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    int num;
    string expected;
    fin >> num;
    fin.get();   // eat newline char
    getline(fin, expected);

    cout << num << ": num" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.numberToWords(num) << ": actual" << endl;
    return 0;
}
