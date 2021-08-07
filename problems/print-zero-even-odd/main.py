#!/usr/bin/python3

import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.lock_leading = threading.Lock()
        self.lock_num_even = threading.Lock()
        self.lock_num_odd = threading.Lock()
        self.lock_num_even.acquire()
        self.lock_num_odd.acquire()

	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            self.lock_leading.acquire()
            printNumber(0)
            if (i % 2 == 0):
                self.lock_num_odd.release()
            else:
                self.lock_num_even.release()

    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n + 1, 2):
            self.lock_num_even.acquire()
            printNumber(i)
            self.lock_leading.release()

    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1, 2):
            self.lock_num_odd.acquire()
            printNumber(i)
            self.lock_leading.release()
