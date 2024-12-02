#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // This is also LC soln #2.
    // In my approach, I just need to read and sort the first numbers in nums. Once the smallest number is
    // discarded, the next number in the same row is read and sorted. After that we update curr_min and
    // curr_max. When it reaches the last number in any of the vector<int> in nums, the current res is the
    // solution.
    //
    //   4     10    15       24 26
    // 0     9    12      20
    //     5           18    22     30
    // Time complexity O(nlogk) I would have expected this would take less time executing, compared to
    // LC soln #3, since k is smaller than n. However, this takes more time executing on LC platform.
    // Space complexity O(k)
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res(2), curr_nums_idx(nums.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nums_order;
        int curr_min = INT_MAX, curr_max = INT_MIN;
        for (int k = 0; k < nums.size(); k++) {
            nums_order.push({nums[k][0], k});
            curr_max = max(curr_max, nums[k][0]);
        }
        res[0] = curr_min = nums_order.top().first;
        res[1] = curr_max;
        if (res[0] == res[1]) return {res[0], res[0]};   // return the shortest range
        while (nums_order.size()) {
            auto [num, curr_row] = nums_order.top();
            if (++curr_nums_idx[curr_row] == nums[curr_row].size()) break;
            nums_order.pop();
            nums_order.push({nums[curr_row][curr_nums_idx[curr_row]], curr_row});
            curr_min = nums_order.top().first;
            curr_max = max(curr_max, nums[curr_row][curr_nums_idx[curr_row]]);
            if (abs(res[1] - res[0]) > abs(curr_max - curr_min)) {
                res[0] = curr_min;
                res[1] = curr_max;
                if (res[0] == res[1]) return {res[0], res[0]};   // return the shortest range
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
