#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int>& w) : dist(w.size(), 0) {
        int size = w.size();
        for (int i = 0; i < size; i++) {
            sum += w[i];
            dist[i] = sum - 1;
        }
    }

    int pickIndex() {
        return lower_bound(dist.begin(), dist.end(), rand() % sum) - dist.begin();
    }
private:
    vector<int> dist;
    int sum = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */