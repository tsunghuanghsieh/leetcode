#include <fstream>
#include <iostream>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"
#include "Solution3.cpp"

int main(int argc, char **argv)
{
    Solution soln;
    Solution2 soln2;
    Solution3 soln3;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    int n, k, target, expected;
    fin >> n >> k >> target >> expected;
    cout << n << ": n" << endl;
    cout << k << ": k" << endl;
    cout << target << ": target" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.numRollsToTarget(n, k, target) << ": actual sol" << endl;
    cout << soln2.numRollsToTarget(n, k, target) << ": actual soln2" << endl;
    cout << soln3.numRollsToTarget(n, k, target) << ": actual soln3" << endl;
    return 0;
}
