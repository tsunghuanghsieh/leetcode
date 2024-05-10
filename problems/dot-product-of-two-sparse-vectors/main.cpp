#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string s1, s2;
    int expected;
    fin >> s1 >> s2 >> expected;
    regex patternNumber("\\d+");
    vector<int> nums1, nums2;
    sregex_token_iterator itr1(s1.begin(), s1.end(), patternNumber);
    sregex_token_iterator itr2(s2.begin(), s2.end(), patternNumber);
    for (; itr1 != sregex_token_iterator(); itr1++, itr2++) {
        nums1.emplace_back(stoi(itr1->str()));
        nums2.emplace_back(stoi(itr2->str()));
    }
    SparseVector sv1(nums1), sv2(nums2);
    cout << s1 << ": input v1" << endl;
    cout << s2 << ": input v2" << endl;
    cout << expected << ": expected" << endl;
    cout << sv1.dotProduct(sv2) << ": actual" << endl;
    return 0;
}