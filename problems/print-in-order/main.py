#!/usr/bin/python3

import threading

class Foo:
    def __init__(self):
        self.lock_second = threading.Lock()
        self.lock_third = threading.Lock()
        self.lock_second.acquire()
        self.lock_third.acquire()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.lock_second.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.lock_second: # one way
            # printSecond() outputs "second". Do not change or remove this line.
            printSecond()
            self.lock_third.release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.lock_third.acquire() # another way
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
