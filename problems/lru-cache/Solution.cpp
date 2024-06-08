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
        if (kv.find(key) == kv.end()) return -1;
        // In LC Editorial, it simply remove the element without explicitly freeing the pointer
        // and add the same element to the newest. I am freeing the point in remove.
        return update(kv[key], kv[key]);
    }

    void put(int key, int value) {
        DoublyLinkedNode *node = new DoublyLinkedNode(key, value);
        if (kv.find(key) != kv.end()) {
            // In LC Editorial, it simply remove the element without explicitly freeing the pointer
            // and add a newly created element to the newest. I am freeing the point in remove.
            update(kv[key], node);
        }
        else {
            if (kv.size() == _capacity) {
                remove(oldest->next);
            }
            insert(node);
        }
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

    void insert(DoublyLinkedNode *node) {
        node->next = newest;
        node->prev = newest->prev;
        newest->prev->next = node;
        newest->prev = node;
        kv.insert({node->getKey(), node});
    }

    void remove(DoublyLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        kv.erase(node->getKey());
        delete(node);
    }

    int update(DoublyLinkedNode *source, DoublyLinkedNode *destination) {
        source->next->prev = source->prev;
        source->prev->next = source->next;
        newest->prev->next = destination;
        destination->prev = newest->prev;
        newest->prev = destination;
        destination->next = newest;
        if (source != destination) {
            delete(source);
            kv[destination->getKey()] = destination;
        }
        return destination->getValue();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
