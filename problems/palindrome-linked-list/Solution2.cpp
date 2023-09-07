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
        bool result = true;
        ListNode *fast = head, *slow = head;
        // Run through the list to get the middle node
        // at each iteration, slow advances 1 node and fast advances 2 nodes
        while (fast != NULL) {
            fast = fast->next;
            if (fast) fast = fast->next;
            if (fast) slow = slow->next;
        }
        ListNode *last = slow;
        slow = last->next;
        // Reverse the second half to compare against the first half
        reverseListNode(slow);
        ListNode *front = head;
        ListNode *back = slow;
        while (back) {
            result = result && (back->val == front->val);
            back = back->next;
            front = front->next;
        }
        // TODO: restore the linked list node
        return result;
    }

private:
    // Pass in a reference to a pointer
    void reverseListNode(ListNode *&head) {
        ListNode *prev = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }
    void printListNode(ListNode *head) {
        ListNode *ptr = head;
        while (ptr) {
            cout << "ptr->val " << ptr->val << endl;
            ptr = ptr->next;
        }
    }
};