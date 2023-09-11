#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> smap, tmap;
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        for (pair<char, int> p : smap) {
            if (tmap[p.first] != p.second) return false;
        }
        return true;
    }
};