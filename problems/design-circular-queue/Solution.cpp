#include <iostream>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) : _className(__func__), length(k), count(0) {
    }

    // For main.cpp setup check
    string ClassName() {
        return _className;
    }

    bool enQueue(int value) {
        if (length == count) return false;
        if (head == nullptr) {
            head = new List(value);
            head->next = tail = head;
        }
        else {
            List *node = new List(value), *temp = tail;
            if (head == tail) {
                head->next = tail = node;
            }
            else {
                tail = tail->next = node;
            }
            node->next = head;
        }
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (--count == 0) head = tail = nullptr;
        else {
            List *temp = head;
            tail->next = head = head->next;
            delete temp;
        }
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return head->value;
    }

    int Rear() {
        if (isEmpty()) return -1;
        return tail->value;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == length;
    }

private:
    const string _className; // For main.cpp setup check
    class List {
    public:
        List(int n) : value(n), next(nullptr) {}
        int value;
        List *next;
    };
    List *head = nullptr, *tail = nullptr;
    int length{}, count{};
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */