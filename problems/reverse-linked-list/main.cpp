#include <iostream>
#include <stddef.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *next;
        if (!head || !head->next) return head;

        next = head->next;
        prev = head;
        prev->next = NULL;
        while (next) {
            head = next;
            next = next->next;
            head->next = prev;
            prev = head;
        }
        return head;
    }
};


int main() {
    Solution s;
    ListNode *head = new ListNode(1);

    s.reverseList(head);
    return 1;
}