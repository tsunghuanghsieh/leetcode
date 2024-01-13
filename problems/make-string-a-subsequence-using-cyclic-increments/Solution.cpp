#include <string>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        bool res = false;
        int str1s = str1.size() - 1;
        if (str2.size() > str1.size()) return false;

        for (int i = str2.size() - 1; i >= 0; i--) {
            res = false;
            for (int j = str1s; j >= 0; j--) {
                if (str1[j] - str2[i] == 0 || str1[j] - str2[i] == -1 || str1[j] - str2[i] == 25) {
                    res = true;
                    str1s = j - 1;
                    break;
                }
            }
            if (!res) return res;
        }
        return res;
    }
};
