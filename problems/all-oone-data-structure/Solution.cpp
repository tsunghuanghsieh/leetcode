#include <iostream>
#include <unordered_map>

using namespace std;

class AllOne {
public:
    // Use doubly linked list to keep track of the list of strings and their respective count.
    // Each item contains the string, its count and links to its prev and next item(s).
    // Unordered maps provide constant time access to items using string and count (not entirely true).
    // At each increment, the incoming item, newly created or existing, will be moved in the list if there
    // exists item(s) at the incremented count or the incoming item is not the first item at the previous
    // count prior to increment.
    //
    //     ______________________________________________
    //     \-> |a| -> |b| -> |c| -> |d| -> |e| -> |f| --/  next*
    //     /-- |5| <- |3| <- |3| <- |3| <- |2| <- |2| <-\  prev*
    //     \____________________________________________/
    AllOne() : _className(__func__) {

    }

    // For main.cpp setup check
    string ClassName() {
        return _className;
    }

    void inc(string key) {
        Item *item;
        if (keys.count(key) == 0) keys[key] = item = new Item(key);
        else (item = keys[key])->size++;
        if (item->size != 1) {   // existing item
            if (keys_freq[item->size - 1] == item) {
                // first and more than one items at the previous count, make the next one the first item
                if (item->next->size == item->size - 1) keys_freq[item->size - 1] = item->next;
                // first and only one items at the previous count, remove previous count from keys_freq
                // update MinCount when prevous count is the MinCount
                else {
                    keys_freq.erase(item->size - 1);
                    if (MinCount == item->size - 1) MinCount = item->size;
                }
            }
            // not the first item and not the only item at the prevous count
            if (item->size != item->next->size) {
                // unhook from the previous location
                item->prev->next = item->next;
                item->next->prev = item->prev;
                // insert at the new location
                int index = (keys_freq.count(item->size) > 0) ? item->size : item->next->size;
                item->prev = keys_freq[index]->prev;
                item->next = keys_freq[index];
                keys_freq[index]->prev->next = item;
                keys_freq[index]->prev = item;
            }
        }
        else {   // new item created
            if (items != nullptr) {
                if (keys_freq.count(item->size) == 0) {
                    // count 1 has no existing item, append to the end of the list
                    item->prev = items->prev;
                    item->next = items;
                    items->prev->next = item;
                    items->prev = item;
                    MinCount = item->size;
                }
                else {
                    // insert before the first item at count 1
                    item->prev = keys_freq[item->size]->prev;
                    item->next = keys_freq[item->size];
                    keys_freq[item->size]->prev->next = item;
                    keys_freq[item->size]->prev = item;
                }
            }
        }
        keys_freq[item->size] = item;   // update the first item at the incremented count
        MaxCount = max(MaxCount, keys[key]->size);
        if (MinCount == 0) MinCount = MaxCount;
        items = keys_freq[MaxCount];
    }

    void dec(string key) {
        Item *item = keys[key];
        --item->size;
        // only 1 item in the doubly linked list
        if (item->next == item) {
            keys_freq.erase(item->size + 1);
            if (item->size) keys_freq[item->size] = item;
            else {
                keys.erase(key);
                delete item;
                items = item = nullptr;
            }
            MaxCount = MinCount = (item != nullptr) ? item->size : 0;
            return;
        }
        Item *temp = item->next;
        // finding the last item of the previous count before the first item of the decrement count
        // this operation is not constant time
        while (temp->size > item->size) temp = temp->next;
        if (item->size > 0) {   // decrement count is more than 0
            MinCount = min(MinCount, item->size);
            // first item and more than one item at the previous count
            if (keys_freq[item->size + 1] == item && item->next->size == item->size + 1) keys_freq[item->size + 1] = item->next;
            // not the last item at the previous count
            if (item->next != temp) {
                // unhook from the previous location
                item->prev->next = item->next;
                item->next->prev = item->prev;
                // insert at the new location
                item->prev = temp->prev;
                item->next = temp;
                temp->prev->next = item;
                temp->prev = item;
            }
            keys_freq[item->size] = item;   // update the first item at the incremented count
            if (MaxCount == item->size + 1 && keys_freq[item->size + 1] == item &&
                item->next->size != item->size + 1) {
                // only 1 item at the previous count
                keys_freq.erase(MaxCount);
                MaxCount = item->size;
            }
        }
        else {   // decremented count is 0
            // first item at the previous count
            if (keys_freq[item->size + 1] == item) {
                // only item at the previous count
                if (item->next->size != item->size + 1) {
                    MinCount = item->prev->size;
                    keys_freq.erase(item->size + 1);
                }
                // more than one items at the previous count
                else {
                    keys_freq[item->size + 1] = item->next;
                }
            }
            // unhook from the previous location
            item->next->prev = item->prev;
            item->prev->next = item->next;
            keys.erase(key);
            delete item;
        }
    }

    string getMaxKey() {
        return (MaxCount)? keys_freq[MaxCount]->key : "";
    }

    string getMinKey() {
        return (MinCount) ? keys_freq[MinCount]->key : "";
    }
private:
    struct Item {
        string key;
        int size = 1;
        Item *next, *prev;
        Item(string s) : key(s), next(this), prev(this) {}
    };

    const string _className; // For main.cpp setup check
    Item *items = nullptr;   // head of doubly linked list
    unordered_map<string, Item*> keys;
    unordered_map<int, Item*> keys_freq;
    int MaxCount = 0, MinCount = 0;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
