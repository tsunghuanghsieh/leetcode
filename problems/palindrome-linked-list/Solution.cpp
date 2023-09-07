#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#ifndef __LISTNODE_STRUCT
#define __LISTNODE_STRUCT
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;

        for (ListNode *ptr = head; ptr != NULL; ptr = ptr->next) {
            nums.emplace_back(ptr->val);
        }
        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] != nums[nums.size() - 1 - i]) return false;
        }
        return true;
    }
};