#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

class DoublyLinkListNode {
public:
    DoublyLinkListNode(double num): num(num), next(nullptr), prev(nullptr) {}
    double num;
    std::shared_ptr<DoublyLinkListNode> next, prev;
};

class Solution {
public:
    // The initial thought was to use a doubly linked list and vector to enable constant
    // insertion, deletion and median update runtime complexity, thinking the implementation
    // could be compact and trivial. However, inserting and removing at head, tail and in
    // between, as well as manually maintaining mid in the sliding window turns out requiring
    // different logic and introduces code complexity. In the end, I would recommend against
    // this implementation.

    // Using map to order value and its index in nums, runtime complexity of finding insertion
    // point is ~O(nlogk). Overall time complexity is ~O(nlogk).
    // Space complexity is O(n + k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        vector<std::shared_ptr<DoublyLinkListNode>> nodes(nums.size(), nullptr);
        std::shared_ptr<DoublyLinkListNode> head = nullptr, tail = nullptr, mid = nullptr;
        map<int, deque<int>> mapNodes;   // key: nums[i], value: deque of i
        int cnt_left = 0, cnt_right = 0;   // count left/right of mid
        for (int i = 0; i < nums.size(); i++) {
            std::shared_ptr<DoublyLinkListNode> node = std::make_shared<DoublyLinkListNode> (nums[i]);
            nodes[i] = node;
            if (!head) {
                mapNodes[nums[i]].emplace_back(i);
                head = tail = mid = node;
            }
            else {
                auto itr = mapNodes.upper_bound(nums[i]);   // find the smallest larger number
                // add new node before the smallest larger number
                if (itr == mapNodes.end()) {
                    // append to the end
                    itr = prev(itr);
                    nodes[itr->second.back()]->next = tail = node;
                    node->prev = nodes[itr->second.back()];
                }
                else {
                    if (!nodes[itr->second.front()]->prev) {
                        // prepend to the head
                        node->next = nodes[itr->second.front()];
                        head = nodes[itr->second.front()]->prev = node;
                    }
                    else {
                        // insert in the middle
                        node->prev = nodes[itr->second.front()]->prev;
                        node->next = nodes[itr->second.front()];
                        nodes[itr->second.front()]->prev = nodes[itr->second.front()]->prev->next = node;
                    }
                }
                mapNodes[nums[i]].emplace_back(i);
                // update mid after adding new node
                if (nums[i] >= mid->num) cnt_right++;
                else cnt_left++;
                if (cnt_left < cnt_right) {
                    mid = mid->next;
                    cnt_left++;
                    cnt_right--;
                }
                else if (cnt_left == cnt_right + 2) {
                    mid = mid->prev;
                    cnt_left--;
                    cnt_right++;
                }
            }
            if (i >= k - 1) {
                // remove oldest node
                if (i >= k) {
                    if (nodes[i - k]->prev) {
                        // not the first node in sliding window
                        nodes[i - k]->prev->next = nodes[i - k]->next;
                        if (nodes[i - k]->next) nodes[i - k]->next->prev = nodes[i - k]->prev;
                        else tail = nodes[i - k]->prev;
                    }
                    else {
                        // removing first node in sliding window
                        head = nodes[i - k]->next;
                        nodes[i - k]->next->prev = nodes[i - k]->prev;
                    }
                    mapNodes[nums[i - k]].pop_front();
                    if (mapNodes[nums[i - k]].size() == 0) mapNodes.erase(nums[i - k]);
                    // update median
                    if (nums[i - k] > mid->num) cnt_right--;   // case 1
                    else if (nums[i - k] < mid->num) cnt_left--;   // case 2
                    else if (nums[i - k] == mid->num && nodes[i - k] != mid) cnt_left--;   // case 3
                    if (cnt_left < cnt_right) {   // only k is even and case 2 or 3
                        mid = mid->next;
                        cnt_left++;
                        cnt_right--;
                    }
                    else if (cnt_left == cnt_right + 2) {   // only k is odd and case 1
                        mid = mid->prev;
                        cnt_left--;
                        cnt_right++;
                    }
                    else if (k & 1 && cnt_left == cnt_right + 1) {   // k is odd, mid removed
                        mid = mid->prev;
                        cnt_left--;
                    }
                    else if ((k & 1) == 0 && cnt_left == cnt_right) {   // k is even, mid removed
                        mid = mid->next;
                        cnt_right--;
                    }
                    // else do nothing
                    // k is even, case 1. k is odd, case 2 or 3.
                }
                // get median
                if (k & 1) res.emplace_back(mid->num);
                else res.emplace_back(((double) mid->num + (double) mid->prev->num) / 2.0);
            }
        }
        return res;
    }
private:
    // Print values in the list from head to tail
    void printDoublyLinkListNode(std::shared_ptr<DoublyLinkListNode> head) {
        std::shared_ptr<DoublyLinkListNode> temp = head;
        cout << "printDoublyLinkListNode ";
        while (temp) {
            cout << temp->num << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
