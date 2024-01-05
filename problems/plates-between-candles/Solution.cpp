#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candles_pos_l(s.size()), candles_pos_r(s.size()), candle_count(s.size()), result;

        for (int front = 0, back = s.size() - 1, cnt = 1, idx_l = -1, idx_r = -1; front < s.size(); front++, back--) {
            if (s[front] == '|') {
                idx_l = front;
                candle_count[front] = cnt++;
            }
            candles_pos_l[front] = idx_l;
            if (s[back] == '|') {
                idx_r = back;
            }
            candles_pos_r[back] = idx_r;
        }

        for (vector<int> range : queries) {
            int candle_pos_l = candles_pos_r[range[0]], candle_pos_r = candles_pos_l[range[1]];
            if (candle_pos_l > range[1] || candle_pos_r < range[0]) {
                result.emplace_back(0);
                continue;
            }
            result.emplace_back(candle_pos_r - candle_pos_l - 1 - (candle_count[candle_pos_r] - candle_count[candle_pos_l] - 1));
        }

        return result;
    }
};
