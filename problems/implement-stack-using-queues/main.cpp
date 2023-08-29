#include <regex>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include "MyStack.cpp"

using namespace std;

static map<string, int> queOps;

int getOpVal(string opVal) {
    return (queOps.find(opVal) != queOps.end()) ? queOps[opVal.c_str()] : queOps.size() + 1;
}

int main(int argc, char** argv) {
    MyStack myStack;
    ifstream fin(argv[1]);
    vector<string> ops;
    vector<string> vals;
    int lc = 0;
    string line, op, val;
    queOps["empty"] = 0;
    queOps["pop"] = 1;
    queOps["push"] = 2;
    queOps["top"] = 3;
    queOps[myStack.ClassName()] = 4;

    // Sample input
    // ["MyStack","push","push","top","pop","empty"]
    // where first value has to be the name of the class.
    // [[],[1],[2],[],[],[]]
    // first value has to be empty and push can have only 1 value.
    regex fmt("(\\[|\\]|\")");
    fin >> line;
    stringstream ssOps(line);
    while (std::getline(ssOps, op, ',')) {
        ops.emplace_back(std::regex_replace(op, fmt, ""));
    }
    fin >> line;
    stringstream ssVals(line);
    while (std::getline(ssVals, val, ',')) {
        vals.emplace_back(std::regex_replace(val, fmt, ""));
    }

    // prevent accidental input mismatch errors
    if (ops.size() != vals.size()) return -1;

    for (int i = 0; i < ops.size(); i++) {
        switch (getOpVal(ops[i]))
        {
        case 0:
            // empty
            myStack.empty();
            break;
        case 1:
            // pop
            cout << myStack.pop() << endl;
            break;
        case 2:
            // push
            cout << "stoi " << stoi(vals[i]) << endl;
            myStack.push(stoi(vals[i]));
            break;
        case 3:
            // top
            cout << myStack.top() << endl;
            break;
        case 4:
            // class name
            cout << "ClassName " << myStack.ClassName() << endl;
            break;
        default:
            cout << "Uknown Op " << ops[i] << endl;
            break;
        }
    }

    return 0;
}