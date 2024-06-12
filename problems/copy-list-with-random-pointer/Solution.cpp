#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *h = nullptr, *hc = nullptr, *curr = head;
        unordered_map<Node*, int> old_addresses;   // key: old Node addresses, value: index
        vector<unsigned long> new_addresses;   // new Node addresses (62-bit or 8 bytes) cast to unsigned long
        int idx = 0;
        while (curr) {
            Node *node = new Node(curr->val);
            if (!h) h = hc = node;
            else {
                hc->next = node;
                hc = hc->next;
            }
            new_addresses.emplace_back((unsigned long) hc);   // new Node address stored as unsigned long
            old_addresses[curr] = idx++;   // old Node address and its respective index
            curr = curr->next;
        }
        curr = head;
        hc = h;
        while (curr) {
            // find index of current old Node random pointer
            if (old_addresses.count(curr->random)) hc->random = (Node*) new_addresses[old_addresses[curr->random]];
            curr = curr->next;
            hc = hc->next;
        }
        return h;
    }
};
