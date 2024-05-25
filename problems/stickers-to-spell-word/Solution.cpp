#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln for optimized brute force goes a step further to reduce the number of stickers
    // by comparing every alphabet in a sticker, count of all alphabets in a sticker >= to another sticker.
    //
    // It uses class scope variables, 1D or 2D int arrays for target and stickers respectively,
    // to allow direct access in functions, eliminating variable constructor calls from function call/return.
    // It also uses array for target to store updated target after a sticker is applied, and restore after done.
    //
    // My approach is top-down. Its approach is bottom-up. It claims it will find the answer faster.
    int minStickers(vector<string>& stickers, string target) {
        map<int, int> mt;
        set<char> chars;
        set<map<int, int>> mts, stck_unique;
        vector<map<int, int>> m_stickers;

        // convert string to frequency
        for (char c : target) mt[c - 'a']++;
        // convert common alphabets with target in stickers to frequency (no duplicates)
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
        // use bfs since it's finding the least stickers
        //                         target
        //      1             2             3             4
        //  1  2  3  4    1  2  3  4    1  2  3  4    1  2  3  4
        // 1,2 == 2,1; 1,3 == 3,1; 1,4 == 4,1
        // 2,3 == 3,2; 2,4 == 4,2
        // 3,4 == 4,3
        // etc
        // so we can skip 1 in 2nd sticker, 1 and 2 in 3rd sticker, so on and so forth.
        // when pusing to the queue, we can include the index to skip duplicating operations.
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
    // Apply sticker to target and return the remaining frequency in target
    map<int, int> applySticker(map<int, int> current, map<int, int> sticker) {
        map<int, int> updated;
        for (auto [key, val] : current) {
            if (current[key] > 0 && current[key] - sticker[key] > 0) {
                updated[key] = current[key] - sticker[key];
            }
        }
        return  updated;
    }

    // helper function to output map content to console for debug
    void printMap(map<int, int> target) {
        for (auto [key, val] : target) {
            char c = key + 'a';
            cout << c << " " << val << "   ";
        }
        cout << endl;
    }
};
