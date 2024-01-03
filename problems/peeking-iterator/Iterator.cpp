#include <vector>

using namespace std;

class Iterator {
    struct Data {
        int value;
        Data *next;
    };
    Data* data;
    vector<int> _nums;

    void insertData(int num) {

    }
public:
    Iterator(const vector<int>& nums) {
        // assign nums to data
        data = nullptr;
        Data *prev = data;
        for (int num : nums) {
            Data *curr = new Data();
            curr->value = num;
            curr->next = nullptr;
            if (!data) data = prev = curr;
            else {
                prev->next = curr;
                prev = curr;
            }
        }
    };
    Iterator(const Iterator& iter) {
        Data *temp = iter.data, *prev = nullptr;
        while (temp) {
            Data *curr = new Data();
            curr->value = temp->value;
            curr->next = nullptr;
            if (!data) data = prev = curr;
            else {
                prev->next = curr;
                prev = curr;
            }
            temp = temp->next;
        }
    };

    // Returns the next element in the iteration.
    int next() {
        int res = data->value;
        Data *curr = data;
        data = data->next;
        delete(curr);
        return res;
    };

    // Returns true if the iteration has more elements.
    bool hasNext() const {
        return data->next != nullptr;
    };
};
