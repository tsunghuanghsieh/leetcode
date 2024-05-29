#include <iostream>
#include <vector>

using namespace std;

class Solution_dp {
public:
    // LC Editorial dynamic programming approach
    // Similar concept as Frog Jump (https://github.com/tsunghuanghsieh/leetcode/tree/master/problems/frog-jump/).
    int minStickers(vector<string>& stickers, string target) {
        // states is the decimal representation of the bitmask for the common letters in target and stickers.
        // e.g., target.size() == 3, there are 8 possible states, 000 to 111.
        //
        // For example, target is "thehat" and sticker is "with".
        //  t  h  e  h  a  t
        //  1  2  4  8 16 32
        // states[3] is set, since th in "thehat" match "with".
        vector<int> states(1 << target.size(), -1);
        states[0] = 0;

        for (int state = 0; state < states.size(); state++) {
            if (states[state] == -1) continue;   // no sticker leads to this states
            // The same optimizations (checking only common letters, removing duplicate and dominated stickers)
            for (string s : stickers) {
                int curr = state;   // current set bits (letters)
                for (char c : s) {
                    for (int i = 0; i < target.size(); i++) {
                        if (((curr >> i) & 1) == 1) continue;   // skip letter that's already set
                        if (target[i] == c) {
                            curr |= 1 << i;   // set letter in its respective position
                            break;
                        }
                    }
                }
                // upddate state after sticker is applied
                if (states[curr] == -1 || states[curr] > states[state] + 1) {
                    states[curr] = states[state] + 1;
                }
            }
        }
        return states[states.size() - 1];
    }
};
