#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        char maxChar;
        map<char, int> freq;
        stringstream ss;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            maxChar = (maxChar == 0 || freq[s[i]] > freq[maxChar]) ? s[i] : maxChar;
        }
        if (freq[maxChar] - 1 > (s.size() - 1) / 2) {
            return "";
        }

        for (int i = 0; i < s.size(); i++) {
            multimap<int, char, greater<int>> temp;
            for (pair<char, int> p : freq) {
                if (p.second > 0) temp.insert({p.second, p.first});
            }
            if (temp.size() == 0) break;
            multimap<int, char>::iterator itr = temp.begin();
            for (int j = 0; j < 2 && itr != temp.end(); j++, itr++) {
                ss << itr->second;
                freq[itr->second]--;
            }
        }

        return ss.str();
    }
};
