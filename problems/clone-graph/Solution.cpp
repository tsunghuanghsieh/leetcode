#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return  nullptr;
        unordered_map<int, Node*> visited;
        Node *res = nullptr;
        queue<Node*> q;
        q.push(node);
        while (q.size() > 0) {
            Node *old = q.front();
            q.pop();
            Node *curr = (visited.find(old->val) == visited.end()) ? new Node(old->val) : visited[old->val];
            if (res == nullptr) res = curr;
            visited[curr->val] = curr;
            for (int i = 0; i < old->neighbors.size(); i++) {
                int n_val = old->neighbors[i]->val;
                if (visited.find(n_val) == visited.end()) q.push(old->neighbors[i]);
                Node *neighbor = (visited.find(n_val) == visited.end()) ? new Node(n_val) : visited[n_val];
                visited[n_val] = neighbor;
                curr->neighbors.emplace_back(neighbor);
            }
        }
        return res;
    }
};
