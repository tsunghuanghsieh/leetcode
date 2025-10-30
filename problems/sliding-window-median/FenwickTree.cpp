#include <iostream>
#include <memory>

using namespace std;

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class FenwickTree {
public:
    // Fenwick Tree (Binary Index Tree)
    // array to compute prefix/range sums
    //
    //               :     1      2      3      4      5      6      7      8      9     10
    // binary        : 00001  00010  00011  00100  00101  00110  00111  01000  01001  01010
    // 2's complement: 11111  11110  11101  11100  11011  11010  11001  11000  10111  10110
    // bitwise and   :     1      2      1      4      1      2      1      8      1      2
    //
    //               :    11     12     13     14     15     16
    // binary        : 01011  01100  01101  01110  01111  10000
    // 2's complement: 10101  10100  10011  10010  10001  10000
    // bitwise and   :     1      4      1      2      1     16
    //
    //  1
    //  |
    //  2   3   5      9
    //  |__/   /      /
    //  4    6   7  10  11  13
    //  |___/___/   /___/   /
    //  8        12       14   15
    //  |________/________/____/
    // 16
    FenwickTree(size_t size) {
        while (msb_value <= size) msb_value <<= 1;
        fenwick = std::make_unique<T []>(msb_value);
    };

    // Returns 1-based index of sum in Fenwick Tree
    // e.g., the tree below is prefix sum of [1, 1, 1, 1]
    //  1
    //  |
    //  2   1
    //  |__/
    //  4
    //  |
    //  4
    size_t getSumIndex(int sum) const {
        size_t idx = 0;
        size_t mask = msb_value >> 1;
        for (; mask; mask >>= 1) {
            size_t next = idx + mask;
            if (fenwick[next] < sum) {
                sum -= fenwick[next];
                idx = next;
            }
        }
        return idx + 1;
    }

    // Return prefix sum of [1, right] (inclusive)
    T getSumAt(int right) const {
        return fenwick[right];
    }

    // Return range sum between [left, right] (inclusive)
    T getSumRange(int left, int right) const {
        return getSumAt(right) - getSumAt(left - 1);
    }

    // Update sum at idx by value
    void update(int idx, T value) {
        // -idx is 2's complement of idx
        // idx += idx & -idx to get the parent index of the current index
        for (; idx < msb_value; idx += idx & -idx) {
            fenwick[idx] += value;
        }
    }

    // Decrement sum at idx by 1
    void decrement(int idx) {
        update(idx, (T) -1);
    }

    // Increment sum at idx by 1
    void increment(int idx) {
        update(idx, (T) 1);
    }
private:
    size_t msb_value = 2;   // most significant bit value
    std::unique_ptr<T []> fenwick;
};
