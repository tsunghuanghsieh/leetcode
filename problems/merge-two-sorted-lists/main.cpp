#include <iostream>
#include <stddef.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;

        if (!l1 || !l2) return (l1) ? l1 : l2;

        result = (l1->val <= l2->val) ? l1 : l2;
        while (l1 && l2) {
            ListNode *temp;
            if (l1->val <= l2->val) {
                while (l1->next && l1->next->val <= l2->val) l1 = l1->next;
                temp = l1->next;
                l1->next = l2;
                l1 = temp;
            } else {
                while (l2->next && l2->next->val <= l1->val) l2 = l2->next;
                temp = l2->next;
                l2->next = l1;
                l2 = temp;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l12 = new ListNode(2);
    ListNode *l14 = new ListNode(4);
    l1->next = l12;
    l12->next = l14;
    ListNode *l2 = new ListNode(1);
    ListNode *l23 = new ListNode(3);
    ListNode *l24 = new ListNode(4);
    l2->next = l23;
    l23->next = l24;

    cout << s.mergeTwoLists(l1, l2) << endl;

    return 0;
}