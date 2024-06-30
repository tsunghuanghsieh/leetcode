#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [] (ListNode* existing, ListNode* incoming) {
            // existing > incoming for min heap
            return existing->val > incoming->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);

        for (int i = 0; i < lists.size(); i++) {
            ListNode *node = lists[i];
            while (node) {
                q.push(node);
                node = node->next;
            }
        }

        ListNode *head = nullptr, *node = nullptr;
        while (q.size() > 0) {
            if (!head) head = node = q.top();
            else {
                ListNode *temp = q.top();
                temp->next = nullptr;
                node->next = temp;
                node = temp;
            }
            q.pop();
        }
        return head;
    }
};
