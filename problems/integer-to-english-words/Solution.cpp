#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> LT20 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                            "Eighteen", "Nineteen" };
    vector<string> SingleDigit = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    vector<string> Multiple10s = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    vector<string> P3S  = { "", "Thousand", "Million", "Billion" };
    string numberToWords(int num) {
        if (num == 0) return SingleDigit[num];
        string res;

        int cnt_p3s = 0;
        while (num) {
            stringstream ss;
            int temp = num % 1000;
            num /= 1000;
            int count = temp / 100;
            if (count) ss << SingleDigit[count] << " Hundred";
            temp %= 100;
            if (temp < 20) {
                if (temp > 0) ss << (!ss.str().empty() ? " " : "")  << LT20[temp];
            }
            else {
                count = temp / 10;
                ss << (!ss.str().empty() ? " " : "") << Multiple10s[count];
                count = temp % 10;
                if (count) ss << (!ss.str().empty() ? " " : "") << SingleDigit[count];
            }
            if (cnt_p3s && !ss.str().empty()) ss << " " << P3S[cnt_p3s];
            if (!ss.str().empty()) res = ss.str() + (!res.empty() ? " " : "") + res;
            cnt_p3s++;
        }
        return res;
    }
};
