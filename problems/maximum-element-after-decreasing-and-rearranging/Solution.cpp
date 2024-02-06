#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // The initial approach was to sort the array, then go through the array and reduce value if needed.
    // The time complexity is bounded by sort O(nlogn).
    // LC Editorial shows a more efficient approach without sorting. See below.
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int size = arr.size();
        int last = 0;
        vector<int> arrCount(size + 1, 0);
        // count the value in the array and store it in a new array (size + 1).
        // if the value is >= size of the input array, store it in index size.
        for (int i = 0; i < size; i++) {
            arrCount[min(arr[i], size)]++;
        }
        // go through the new array to determine the largest value at the index i
        for (int i = 1; i <= size; i++) {
            if (arrCount[i] > 0) {
                last = (last + arrCount[i] > i) ? i : last + arrCount[i];
            }
        }
        return last;
    }
};