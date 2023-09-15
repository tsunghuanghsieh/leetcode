#include <fstream>
#include <iostream>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);

    string s;
    getline(fin, s, '\n');
    // cout << ":" << s << ":" << endl;
    int ans;
    fin >> ans;
    int result = soln.lengthOfLongestSubstring(s);
    cout << "ans " << ans << " result " << result << ": ";
    cout << ((ans == result) ? "correct" : "wrong") << endl;
    return 0;
}