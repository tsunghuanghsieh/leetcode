#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res(2), curr_nums(nums.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_next;
        int curr_min = INT_MAX, curr_max = INT_MIN;
        // key: current smallest number in all vectors of nums
        // value: all indices of the number
        map<int, unordered_set<int>> nums_order;
        for (int k = 0; k < nums.size(); k++) {
            curr_nums[k] = nums[k][0];   // lookup vector of current smallest number in all vectors of nums
            nums_order[nums[k][0]].insert(k);
            curr_min = min(curr_min, nums[k][0]);
            curr_max = max(curr_max, nums[k][0]);
            for (int i = 1; i < nums[k].size(); i++) if (nums[k][i] != nums[k][i - 1]) pq_next.push({nums[k][i], k});
        }
        res[0] = curr_min;
        res[1] = curr_max;
        if (res[0] == res[1]) return {res[0], res[0]};   // return the shortest range
        while (pq_next.size()) {
            int next_num = pq_next.top().first, next_idx = pq_next.top().second;
            // update current smallest number at the incoming index
            nums_order[curr_nums[next_idx]].erase(next_idx);
            if (nums_order[curr_nums[next_idx]].size() == 0) nums_order.erase(curr_nums[next_idx]);
            nums_order[next_num].insert(next_idx);
            // update current smallest number in the lookup vector
            curr_nums[next_idx] = next_num;
            pq_next.pop();
            if (curr_min < nums_order.begin()->first) {
                // a new minimum among the current smallest number in all vectors of nums
                // update curr_min and curr_max
                curr_min = nums_order.begin()->first;
                curr_max = max(curr_max, nums_order.rbegin()->first);
            }
            if (abs(res[1] - res[0]) > abs(curr_max - curr_min)) {
                res[0] = curr_min;
                res[1] = curr_max;
            }
        }

        return res;
    }
private:
    // for easier visualization on spreadsheet
    void print2cvs(vector<vector<int>>& nums) {
        map<int, unordered_set<int>> m;
        for (int k = 0; k < nums.size(); k++) {
            for (int i = 0; i < nums[k].size(); i++) m[nums[k][i]].insert(k);
        }
        for (int k = 0; k < nums.size(); k++) {
            for (auto [key, indices] : m) {
                if (indices.count(k)) cout << key;
                cout << ",";
            }
            cout << endl;
        }
    }
};
