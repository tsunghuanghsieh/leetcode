#include <iostream>

using namespace std;

#include "Solution.cpp"

int main (int argc, char **argv) {
    Solution soln;
    Solution2 soln2;
    int x;

    x = stoi(string(argv[1]));
    // cout << soln.isPalindrome(x) << endl;
    cout << soln2.isPalindrome(x) << endl;
    return 0;
}