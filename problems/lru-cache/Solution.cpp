#include <iostream>
#include <unordered_map>

using namespace std;

#include "DoublyLinkedNode.cpp"

//
// From LC Editorial
//
// Note: in C++, we use Node instead of ListNode.
// This is because LeetCode's online judge environment already has ListNode defined
// (it's the class used in linked list problems).
//

//
// Since elements in unordered_map are ordered into buckets depending on their hash values,
// they are not sorted in any particular order. Map in JS are in the original insertion order of keys.
// As the result, we need to maintain the order of insertion separately in C++.
// Hance, a list, and a doubly-linked list for easy access of previous element.
//
class LRUCache {
public:
    // Since there is no default constructor, and I want to do some checks in the test files,
    // so hardcoding class name in a static variable, instead of using __func__ variable.
    static inline string ClassName = "LRUCache";
    static inline string FuncNameGet = "get";
    static inline string FuncNamePut = "put";

    LRUCache(int capacity) : _capacity(capacity) {
        // dummy oldest and newest so that when an actual element is added
        // we don't have to initialize head and tail
        oldest = new DoublyLinkedNode(-1, -1);
        newest = new DoublyLinkedNode(-1, -1);
        oldest->next = oldest->prev = newest;
        newest->next = newest->prev = oldest;
    }

    int get(int key) {
        auto itr = kv.find(key);
        if (itr != kv.end()) {
            DoublyLinkedNode *node = itr->second;
            node->next->prev = node->prev;
            node->prev->next = node->next;
            newest->prev->next = node;
            node->prev = newest->prev;
            newest->prev = node;
            node->next = newest;
            return node->getValue();
        }
        return -1;
    }

    void put(int key, int value) {
        DoublyLinkedNode *node = new DoublyLinkedNode(key, value);
        auto itr = kv.find(key);
        if (itr != kv.end()) {
            DoublyLinkedNode *old = itr->second;
            old->prev->next = old->next;
            old->next->prev = old->prev;
            delete(old);
            kv.erase(key);
        }
        else {
            if (kv.size() == _capacity) {
                DoublyLinkedNode *old = oldest->next;
                old->next->prev = old->prev;
                oldest->next = old->next;
                kv.erase(old->getKey());
                delete(old);
            }
        }
        node->next = newest;
        node->prev = newest->prev;
        newest->prev->next = node;
        newest->prev = node;
        kv.insert({key, node});
    }

    void printDoublyLinkedNodes() {
        DoublyLinkedNode *node = oldest->next;
        cout << "forward" << endl;
        while (node != newest) {
            cout << "key " << node->getKey() << " value " << node->getValue() << endl;
            node = node->next;
        }
        cout << "backward" << endl;
        node = node->prev;
        while (node != oldest) {
            cout << "key " << node->getKey() << " value " << node->getValue() << endl;
            node = node->prev;
        }
    }
private:
    int _capacity;
    unordered_map<int, DoublyLinkedNode*> kv;
    DoublyLinkedNode *oldest, *newest;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
