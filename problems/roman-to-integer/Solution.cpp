#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> sv = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int year = 0;
        int prev_year = INT_MAX;
        for (char c : s) {
            int curr_year = sv[c];
            if (prev_year < curr_year) {
                year += (curr_year - prev_year * 2);
                prev_year = INT_MAX;
            }
            else
                year += curr_year;
            prev_year = curr_year;
        }
        return year;
    }
};
