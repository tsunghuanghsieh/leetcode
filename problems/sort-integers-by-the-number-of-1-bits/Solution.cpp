#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> result;
        map<int, vector<int>> bitNum;
        sort(arr.begin(), arr.end());

        for (int num : arr) {
            int cnt = getPopCount(num);
            if (bitNum.find(cnt) == bitNum.end()) bitNum.emplace(cnt, vector<int>{num});
            else bitNum.at(cnt).emplace_back(num);
        }
        for (pair<int, vector<int>> p : bitNum) {
            for (int num : p.second) {
                result.emplace_back(num);
            }
        }
        return result;
    }
private:
    // Get binary bit summation of the integral number
    int getPopCount(int num) {
        int count = 0;
        while (num) {
            if (num % 2) count++;
            num /= 2;
        }
        return count;
    }
};