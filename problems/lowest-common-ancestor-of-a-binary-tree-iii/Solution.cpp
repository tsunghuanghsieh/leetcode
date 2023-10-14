#include <iostream>
#include <stack>

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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *result;
        stack<Node*> stack_p, stack_q;
        Node *temp_p = p, *temp_q = q;

        while (temp_p) {
            stack_p.push(temp_p);
            temp_p = temp_p->parent;
        }
        while (temp_q) {
            stack_q.push(temp_q);
            temp_q = temp_q->parent;
        }
        while (stack_p.top() == stack_q.top()) {
            result = stack_p.top();
            stack_p.pop();
            stack_q.pop();
            if (stack_p.size() == 0 || stack_q.size() == 0) break;
        }
        return result;
    }
};