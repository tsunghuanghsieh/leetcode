#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 2; i <= n; i++) {
            string nextStr;
            for (int j = 0, k = 0; k < result.size(); j = k) {
                while (k < result.size() && result[k] == result[k + 1]) k++;
                k++;
                nextStr += to_string(k - j);
                nextStr += result[k - 1];
            }
            result = nextStr;
        }
        return result;
    }
};