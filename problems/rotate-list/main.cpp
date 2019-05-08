#include <iostream>
using namespace std;

#include "ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int length;
        ListNode *temp = head;
        ListNode *lastNode = NULL;
        ListNode *newLastNode = NULL;
        
        // special cases
        if (head == NULL || head->next == NULL || k == 0) return head;
        
        for (length = 0; temp != NULL; length++) {
            if (temp->next == NULL) {
                lastNode = temp;
            }
            temp = temp->next;
        }
        k %= length;
        // no shift, return head as is
        if (k == 0) return head;

        temp = head;
        for (int i = 0; i < length - k; i++) {
            newLastNode = temp;
            temp = temp->next;
        }
        newLastNode->next = NULL;
        lastNode->next = head;
        return temp;
    }

    // Helper function to construct ListNode of
    ListNode *initListNode(int length)
    {
        ListNode *head = new ListNode(-1);
        ListNode *tmp = head;
        for (int i = 0; i < length; i++)
        {
            ListNode *newNode = new ListNode(i);
            tmp->next = newNode;
            tmp = newNode;
        }
        return head->next;
    };

    void printListNode(ListNode *listNode)
    {
        ListNode *temp = listNode;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main()
{
    int k = 12;
    int length = 10;
    Solution s;
    ListNode *head = s.initListNode(length);
    s.printListNode(head);
    head = s.rotateRight(head, k);
    s.printListNode(head);
    return 0;
}
