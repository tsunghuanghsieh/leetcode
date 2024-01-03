#include <iostream>
#include <vector>

#include "Iterator.cpp"

using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *        struct Data;
 *        Data* data;
 *  public:
 *        Iterator(const vector<int>& nums);
 *        Iterator(const Iterator& iter);
 *
 *        // Returns the next element in the iteration.
 *        int next();
 *
 *        // Returns true if the iteration has more elements.
 *        bool hasNext() const;
 *    };
 */

// Once you understand what the question wants you to do, it is actually pretty straightforward.
// Unfortunately, I am not a mind reader.
//
// The initial approach at the EOF below uses a separate member variable of the parent class.
// It uses Iterator interface methods and doesn't explicitly save a copy of nums for manipulations.
// The code is short and simple. However that is probably not what interviewer wants and has to be changed.
//
// Approach 1, (https://leetcode.com/problems/peeking-iterator/editorial/) Premium subscription required,
// violates the requirement of without advancing the iterator in peek().
class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums),  _className(__func__) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        advanceItr();
    }

    // For main.cpp setup check
    string ClassName() {
        return _className;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return peeked;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int res = peeked;
        advanceItr();
        return res;
    }

    bool hasNext() const {
        return bHasNext;
    }

private:
    const string _className;
    int peeked = 0;
    bool bHasNext = false;
    void advanceItr() {
        bHasNext = Iterator::hasNext();
        if (bHasNext) {
            peeked = Iterator::next();
        } else {
			// Constraint says next() calls are valid, however we advance iterator prior to
			// next() is actually called, this may try to advance when itr is already at the end.
			// So, resetting the value to the initial value and not throw any exception.
            peeked = 0;
        }
    };
};

//
// Initial Approach
//
// Use additional member variable of the parent class.
//
// class PeekingIterator : public Iterator {
// public:
//     PeekingIterator(const vector<int>& nums) : Iterator(nums), itr(nums) {
//         // Initialize any member here.
//         // **DO NOT** save a copy of nums and manipulate it directly.
//         // You should only use the Iterator interface methods.
//     }
//
//     // Returns the next element in the iteration without advancing the iterator.
//     int peek() {
//         Iterator temp(itr);
//         return temp.next();
//     }
//
//     // hasNext() and next() should behave the same as in the Iterator interface.
//     // Override them if needed.
//     int next() {
//         return itr.next();
//     }
//
//     bool hasNext() const {
//         return itr.hasNext();
//     }
// private:
//     Iterator itr;
// };
