#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution3 {
public:
    map<string, int> seen;
    int numDecodings(string s) {
        if (s.size() == 0) return 1;
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        if (seen.find(s) != seen.end()) return seen[s];
        int sum = numDecodings(s.substr(1));
        int num = (s[0] - '0') * 10 + s[1] - '0';
        if (num <= 26) {
            sum += numDecodings(s.substr(2));
        }
        seen.insert(make_pair(s, sum));
        return sum;
    }
};
