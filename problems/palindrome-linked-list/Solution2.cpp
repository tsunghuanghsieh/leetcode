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

class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;

        ListNode *fast = head, *slow = head, *curr = head, *prev = nullptr;
        // Run through the list to get the middle node
        // at each iteration, slow advances 1 node and fast advances 2 nodes
        // and reverse first half in the linked list
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            curr->next = prev;
            prev = curr;
            curr = slow;
        }
        // not null (odd numbered length)
        // curr is at the middle node, need to advance 1 node.
        if (fast) curr = curr->next;
        // compare values in first half and second half
        while (curr && prev) {
            if (curr->val != prev->val) return false;
            curr = curr->next;
            prev = prev->next;
        }
        return true;
    }

private:
    void printListNode(ListNode *head) {
        ListNode *ptr = head;
        while (ptr) {
            cout << "ptr->val " << ptr->val << endl;
            ptr = ptr->next;
        }
    }
};