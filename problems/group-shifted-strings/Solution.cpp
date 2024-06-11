#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashtable;
        vector<vector<string>> res;
        for (int i = 0; i < strings.size(); i++) {
            stringstream ss;
            // find the difference between first char and subsequent chars in the string
            // transform first char to a and all subsequent chars accordingly
            // the transformed string will be the hash key
            for (int j = 0, first = strings[i][j]; j < strings[i].size(); j++) {
                int ascii = strings[i][j] - first;
                if (ascii < 0) ascii += 26;
                ss << char('a' + ascii);
            }
            string s = ss.str();
            if (hashtable.count(s) == 0) hashtable[s] = vector<string>({strings[i]});
            else hashtable[s].emplace_back(strings[i]);
        }
        for (auto itr = hashtable.begin(); itr != hashtable.end(); itr++) {
            res.emplace_back((*itr).second);
        }
        return res;
    }
};
