#include <iostream>

using namespace std;

#include "Solution.cpp"

int main (int argc, char **argv) {
    Solution soln;
    int n;

    n = stoi(string(argv[1]));
    vector<string> answer = soln.fizzBuzz(n);
    for (int i = 0; i < n; i++) {
        cout << "i " << answer[i] << endl;
    }
    return 0;
}