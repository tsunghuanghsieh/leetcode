#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node *head = nullptr, *prev = nullptr, *curr = root;
        stack<Node*> snodes;
        if (!root) return head;
        snodes.push(root);
        while (snodes.size() > 0) {
            curr = snodes.top();
            if (curr->left) {
                snodes.push(curr->left);
                curr->left = nullptr;
                continue;
            }
            if (!head) head = curr;
            if (prev) {
                prev->right = curr;
                curr->left = prev;
                prev = curr;
            }
            if (!prev) prev = curr;
            snodes.pop();
            if (curr->right) {
                snodes.push(curr->right);
                curr->right = nullptr;
            }
        }
        curr->right = head;
        head->left = curr;
        return head;
    }
};
