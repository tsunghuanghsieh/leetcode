// I should have .h for declaration, and .cpp for implementation.
// But it's too much boilerplate work for doing leetcode.
// LC expects the class with implementation. It's easier to copy code back.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// This implementation uses 1 queue.
class MyStack {
public:
    MyStack() : _className(__func__) {
    }

    // For main.cpp setup check
    string ClassName() {
        return _className;
    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        int back = q1.back();
        int count = q1.size();
        while (count > 1) {
            q1.push(q1.front());
            q1.pop();
            count--;
        }
        q1.pop();
        return back;
    }

    int top() {
        return q1.back();
    }

    bool empty() {
        return q1.empty();
    }
private:
    const string _className; // For main.cpp setup check
    std::queue<int> q1;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

