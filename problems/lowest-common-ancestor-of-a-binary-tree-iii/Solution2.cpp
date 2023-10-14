#include <iostream>
#include <unordered_set>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

#ifndef __CLASS_NODE
#define __CLASS_NODE
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
#endif

// 2 Runner solution
class Solution2 {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *temp_p = p, *temp_q = q;
        while (temp_p != temp_q) {
            temp_p = (temp_p->parent) ? temp_p->parent : q;
            temp_q = (temp_q->parent) ? temp_q->parent : p;
        }
        return temp_q;
    }
};