#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int size = arr.size();
        int last = 0;
        vector<int> arrCount(size + 1, 0);
        for (int i = 0; i < size; i++) {
            arrCount[min(arr[i], size)]++;
        }
        for (int i = 1; i <= size; i++) {
            if (arrCount[i] > 0) {
                last = (last + arrCount[i] > i) ? i : last + arrCount[i];
            }
        }
        return last;
    }
};