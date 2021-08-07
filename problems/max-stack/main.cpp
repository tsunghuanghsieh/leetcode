#include <iostream>
#include <vector>
using namespace std;

class MaxStack {
public:
    MaxStack() {};

    void push(int x) {
        _stack.push_back(x);
        if (_stackMax.size() == 0 || _stackMax.back() <= x) {
            _stackMax.push_back(x);
        } else {
            // making _stackMax the same length as _stack
            _stackMax.push_back(_stackMax.back());
        }
    };

    int pop() {
        int top = _stack.back();
        _stack.pop_back();
        _stackMax.pop_back();
        return top;
    };

    int popMax() {
        int max = _stackMax.back();

        vector<int> tmp;
        while (_stack.back() != max) {
            tmp.push_back(_stack.back());
            // pop from both _stack and _stackMax
            pop();
        }
        pop();
        while (tmp.size() > 0) {
            // push to both _stack and _stackMax
            push(tmp.back());
            tmp.pop_back();
        }

        return max;
    }

    int peek() {
        return _stack.back();
    };

    int peekMax() {
        return _stackMax.back();
    };

    bool is_empty() {
        return _stack.empty();
    };

private:
    vector<int> _stack;
    vector<int> _stackMax;
};

int main() {
    MaxStack ms;

    // ms.push(2);
    // cout << ms.peekMax() << endl;
    // ms.push(6);
    // cout << ms.peekMax() << endl;
    // ms.pop();
    // cout << ms.peekMax() << endl;

    // ms.push(6);
    // cout << ms.peekMax() << endl;
    // ms.push(2);
    // cout << ms.peekMax() << endl;
    // ms.popMax();
    // cout << ms.peekMax() << endl;

    // ms.push(5);
    // cout << ms.peekMax() << endl;
    // ms.push(1);
    // cout << ms.peekMax() << endl;
    // ms.push(5);
    // cout << ms.peekMax() << endl;
    // ms.pop();
    // cout << ms.peekMax() << endl;
    // ms.popMax();
    // cout << ms.peekMax() << endl;

    ms.push(1);
    cout << ms.peekMax() << endl;
    ms.push(2);
    cout << ms.peekMax() << endl;
    ms.push(5);
    cout << ms.peekMax() << endl;
    ms.push(4);
    cout << ms.peekMax() << endl;
    ms.push(3);
    cout << ms.peekMax() << endl;
    ms.push(7);
    cout << ms.peekMax() << endl;
    ms.pop();
    cout << ms.peekMax() << endl;
    ms.popMax();
    cout << ms.peekMax() << endl;
    ms.popMax();
    cout << ms.peekMax() << endl;
}