#include <format>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <vector>

#include "Solution.cpp"

using namespace std;

static vector<string> mfuns = { "PeekingIterator", "hasNext", "next", "peek" };

int getOpVal(string command) {
    vector<string>::iterator itr = find(mfuns.begin(), mfuns.end(), command);
    return (itr != mfuns.end()) ? itr - mfuns.begin() : -1;
}

// Validation
void printVector(vector<int> nums) {
    cout << " ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    vector<int> nums;
    regex patternOps("\\w+");
    regex patternNumber("-?\\d+");
    string ops, input, expected;
    fstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    fin >> ops >> input >> expected;
    cout << ops << ": command" << endl;
    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;

    sregex_token_iterator itrOps(ops.begin(), ops.end(), patternOps);
    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(atoi((*itr).str().c_str()));
    }
    PeekingIterator pi(nums);
    if (*itrOps != pi.ClassName()) {
        cout << "ERROR: " << argv[1] << " contains incorrect class name, " << *itrOps << "." << endl;
        exit(1);
    }

    cout << "[null,";
    for (itrOps++; itrOps != sregex_token_iterator();) {
        switch (getOpVal(*itrOps))
        {
        case 1:
            cout << boolalpha << pi.hasNext();
            break;
        case 2:
            cout << pi.next();
            break;
        case 3:
            cout << pi.peek();
            break;
        default:
            cout << "Unknown command " << *itrOps << endl;
            break;
        }
        if (++itrOps != sregex_token_iterator()) cout << ',';
    }
    cout << "]: actual" << endl;
    return 0;
}
