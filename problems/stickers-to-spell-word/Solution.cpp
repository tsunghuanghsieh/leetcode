#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        map<int, int> mt;
        set<char> chars;
        set<map<int, int>> mts, stck_unique;
        vector<map<int, int>> m_stickers;

        for (char c : target) mt[c - 'a']++;
        for (string s : stickers) {
            map<int, int> ms;
            for (char c : s) {
                if (mt.count(c - 'a') > 0) {
                    ms[c - 'a']++;
                    chars.insert(c);
                }
            }
            if (ms.size() > 0 && stck_unique.count(ms) == 0) m_stickers.push_back(ms);
            stck_unique.insert(ms);
        }
        if (chars.size() != mt.size()) return -1;

        int count = 0;
        queue<pair<int, map<int, int>>> q;
        q.push({0, mt});
        int qsize = q.size();
        while (qsize > 0) {
            for (int i = 0; i < qsize; i++) {
                pair<int, map<int, int>> curr = q.front();
                q.pop();
                for (int si = curr.first; si < m_stickers.size(); si++) {
                    map<int, int> updated = applySticker(curr.second, m_stickers[si]);
                    if (updated.size() == 0) {
                        return ++count;
                    }
                    if (mts.find(updated) != mts.end()) continue;
                    mts.insert(updated);
                    q.push({si, updated});
                }
            }
            qsize = q.size();
            count++;
        }
        return count;
    }
private:
    map<int, int> applySticker(map<int, int> current, map<int, int> sticker) {
        map<int, int> updated;
        for (auto [key, val] : current) {
            if (current[key] > 0 && current[key] - sticker[key] > 0) {
                updated[key] = current[key] - sticker[key];
            }
        }
        return  updated;
    }
    void printMap(map<int, int> target) {
        for (auto [key, val] : target) {
            char c = key + 'a';
            cout << c << " " << val << "   ";
        }
        cout << endl;
    }
};
