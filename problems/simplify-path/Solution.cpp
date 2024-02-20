#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        // 0: /
        // 1: isalnum or _
        // 2: .
        int lastSeen = 0;
        stringstream fname, ss;
        vector<string> fnames;
        char sep = '/', period = '.';

        for (int i = 1; i < path.size(); i++) {
            if (path[i] != sep) {
                fname << path[i];
                lastSeen = (path[i] == period) ? 2 : 1;
            }
            if (path[i] == sep || i + 1 == path.size()) {
                if (lastSeen == 1 || (lastSeen == 2 && (fname.str().size() > 2 ||
                    (fname.str().size() == 2 && fname.str()[0] != period)))) {
                    fnames.emplace_back(fname.str());
                }
                else if (lastSeen == 2 && fname.str().size() == 2) {
                    if (fnames.size() > 0) fnames.erase(fnames.begin() + fnames.size() - 1);
                }
                fname.str("");
                lastSeen = 0;
            }
        }

        ss << sep;
        for (int i = 0; i < fnames.size(); i++) {
            ss << fnames[i];
            if (i + 1 < fnames.size()) ss << sep;
        }
        return ss.str();
    }
};
