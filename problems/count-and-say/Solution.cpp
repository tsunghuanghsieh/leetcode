#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 2; i <= n; i++) {
            int lastSeen = 0;
            int count = 0;
            string nextStr;
            for (int j = 0; j < result.size(); j++) {
                parseString(result, j, to_string(result[j] - '0'), lastSeen, nextStr, count);
            }
            nextStr += to_string(count);
            nextStr += result[result.size() - 1];
            result = nextStr;
        }
        return result;
    }
private:
    void parseString(string result, int j, string digit, int &lastSeen, string &nextStr, int &count) {
        if (result[j] == digit[0]) {
            if (lastSeen != int(result[j] - '0')) {
                if (lastSeen != 0) {
                    nextStr += to_string(count);
                    nextStr += result[j - 1];
                }
                lastSeen = int(result[j] - '0');
                count = 1;
            }
            else {
                count++;
            }
        }
    }
};