#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        //
        // LC Premium soln #1 uses sorted string as the key
        // LC Premium soln #2 uses count of all 26 letters (array of int) as the key
        //
        // key: count of letters found in the string
        map<map<char, int>, vector<string>> data;
        for (string str : strs) {
            map<char, int> ci;
            for (char ch : str) {
                ci[ch]++;
            }
            data[ci].push_back(str);
        }
        for (auto p : data) {
            result.push_back(p.second);
        }
        return result;
    }
};
