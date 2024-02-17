#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        int size = w.size();
        for (int i = 0; i < size; i++) {
            sum += w[i];
            dist[sum - 1] = i;
        }
    }

    int pickIndex() {
        return dist.lower_bound(rand() % sum)->second;
    }
private:
    map<int, int> dist;
    int sum = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */