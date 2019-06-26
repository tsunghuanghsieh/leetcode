#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        const int length = A.size();
        vector<int> jumpEven(A.size());
        vector<int> jumpOdd(A.size());
        map<int, int> nodes;
        int count = 1;

        // 1: there is a path from current index to the end
        // 0: there is no path from current index to the end
        jumpEven[length - 1] = jumpOdd[length - 1] = 1;

        // key is the element in A
        // value is the index of element in A
        nodes[A[length - 1]] = length - 1;

        for (int idx = length - 2; idx >= 0; idx--) {
            // I could use auto instead as follows.
            // auto itr_find = nodes.find(A[idx]);
            map<int, int>::iterator itr_find = nodes.find(A[idx]);
            // key A[j] already in map
            // key A[j] will be the smallest A[j] where A[i] <= A[j]
            // key A[j] will be the largest A[j] where A[i] >= A[j]
            if (itr_find != nodes.end()) {
                int first = itr_find->first;
                int second = itr_find->second;
                // cout << "index " << idx << " value " << A[idx] << " find first " << first << " second " << second << endl;
                // cout << "jumpEven[" << idx << "] " << jumpEven[idx] << " = jumpOdd[" << second << "] " << jumpOdd[second] << endl;
                // cout << "jumpOdd[" << idx << "] " << jumpOdd[idx] << " = jumpEven[" << second << "] " << jumpEven[second] << endl;
                jumpEven[idx] = jumpOdd[second];
                jumpOdd[idx] = jumpEven[second];
            } else {
                // upper_bound() returns the iterator pointing to the first element which key will go after A[idx]
                // A[idx] < itr_ub->first
                map<int,int>::iterator itr_ub = nodes.upper_bound(A[idx]);

                // if iterator is not at the first element in the map
                // the element before the iterator will be the largest element where it is smaller than A[idx]
                // otherwise, there is no element in the map smaller than A[idx] for even jump
                if (itr_ub != nodes.begin()) {
                    int first = prev(itr_ub)->first;
                    int second = prev(itr_ub)->second;
                    // cout << "index " << idx << " value " << A[idx] << " upper first " << first << " second " << second << endl;
                    // cout << "jumpEven[" << idx << "] " << jumpEven[idx] << " = jumpOdd[" << second << "] " << jumpOdd[second] << endl;
                    jumpEven[idx] = jumpOdd[second];
                }
                // if iterator is not at the end of the map
                // the element pointed by iterator will be the smallest element where it is larger than A[idx]
                // otherwise, there is no element in the map larger than A[idx] for odd jump
                if (itr_ub != nodes.end()) {
                    int first = itr_ub->first;
                    int second = itr_ub->second;
                    // cout << "index " << idx << " value " << A[idx] << " lower first " << first << " second " << second << endl;
                    // cout << "jumpOdd[" << idx << "] " << jumpOdd[idx] << " = jumpEven[" << second << "] " << jumpEven[second] << endl;
                    jumpOdd[idx] = jumpEven[second];
                }
            }
            count += jumpOdd[idx];
            nodes[A[idx]] = idx;
        }
        return count;
    }
};


int main() {
    int vals[] = {10,13,12,14,15};
    vector<int> A(vals, vals + sizeof(vals) / sizeof(int));
    Solution s;
    cout << s.oddEvenJumps(A) << endl;
    return 0;
}