#include <iostream>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

#ifndef __CLASS_NODE
#define __CLASS_NODE
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
#endif

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            // empty list
            Node *node = new Node(insertVal);
            head = node->next = node;
        }
        else if (head->next == head) {
            // 1 in the list
            Node *node = new Node(insertVal, head);
            head->next = node;
        }
        else {
            Node *node = new Node(insertVal), *curr = head->next, *prev = head;
            do {
                if (prev->val <= insertVal && insertVal <= curr->val ||
                    prev->val > curr->val && (prev->val <= insertVal || insertVal <= curr->val)) {
                    prev->next = node;
                    node->next = curr;
                    break;
                }
                prev = curr;
                curr = curr->next;
            } while (curr != head);
            if (curr == head) {
                // nodes in  the list have the same value
                prev->next = node;
                node->next = curr;
            }
        }
        return head;
    }
};