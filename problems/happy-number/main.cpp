#include <iostream>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    Solution soln;
    int num = stoi(argv[1]);
    cout << soln.isHappy(num) << endl;
    return 0;
}