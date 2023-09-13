#include <iostream>

#include "Solution.cpp"

using namespace std;


int main(int argc, char **argv) {
    Solution soln;

    cout << "Complement is " << soln.bitwiseComplement(stoi(argv[1])) << endl;
    return 0;
}