#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        set<int> s;

        for (int n : arr) {
            if (m.find(n) == m.end()) {
                m.insert(make_pair(n, 1));
            }
            else {
                m[n] += 1;
            }
        }
        bool insertResult = true;
        for (pair<int, int> p : m) {
            pair<set<int>::iterator, bool> result = s.insert(p.second);
            insertResult = insertResult && result.second;
        }
        return insertResult;
    }
};