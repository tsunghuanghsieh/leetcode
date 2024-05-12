#include <iostream>
#include <vector>

using namespace std;

#ifndef __NestedInteger__
#define __NestedInteger__

// Based on empirical data
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger() {}

    // Constructor initializes a single integer.
    NestedInteger(int value) : _value(value), _isInteger(true) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
      return _isInteger;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
      // If NestInteger holds a nested list, per empirical data, LC implementation will return the value from
      // the last NestInteger that holds a single integer. My implementation will default to 0 instead.
      return _value;
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
      _isInteger = true;
      _value = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
      _isInteger = false;
      _list->emplace_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
      return *_list;
    }
  private:
    bool _isInteger = false;
    int _value = 0;
    vector<NestedInteger> *_list = new vector<NestedInteger>();
};
#endif
