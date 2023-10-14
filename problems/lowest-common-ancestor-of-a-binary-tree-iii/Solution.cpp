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
        unordered_set<Node*> ancestry_p;
        Node *temp = p;

        while (temp) {
            ancestry_p.insert(temp);
            temp = temp->parent;
        }
        temp = q;
        while (ancestry_p.find(temp) == ancestry_p.end()) {
            temp = temp->parent;
        }
        return temp;
    }
};