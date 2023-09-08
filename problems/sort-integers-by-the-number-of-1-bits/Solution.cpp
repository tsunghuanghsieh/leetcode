#include <stdio.h> // Include __builtin_popcount(int)
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compareByPopCount);
        return arr;
    }
private:
    static bool compareByPopCount(const int &a, const int &b) {
        if (getPopCount(a) == getPopCount(b)) return a < b;

        return getPopCount(a) < getPopCount(b);
    }

    // Get binary bit summation of the integral number
    static int getPopCount(int num) {
        int weight = 0;
        while (num) {
            // bitwise compare with mask
            if (num & 1) weight++;
            num >>= 1;
        }
        return weight;
    }
};