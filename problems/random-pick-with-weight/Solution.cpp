#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        int size = w.size();
        sum = accumulate(w.begin(), w.end(), 0);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < w[i]; j++) {
                v_prob.emplace_back(i);
            }
        }
    }

    int pickIndex() {
        return v_prob[rand() % sum];
    }
private:
    vector<int> v_prob;
    int sum = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */