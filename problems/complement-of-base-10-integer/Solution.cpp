#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        // special case when n is 0
        if (!n) return !n;
        int sizeMask = log2(n);
        int mask = 1;
        // creating a mask with the same bit length as n
        mask = ~(~mask << sizeMask);
        return mask ^ n;
    }
};