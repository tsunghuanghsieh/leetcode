#include <math.h>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;

        while (n != 1) {
            int sum = 0;
            while (n > 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            pair<set<int>::iterator, bool> result = seen.insert(sum);
            if (!result.second) return result.second;
            n = sum;
        }
        return true;
    }
};