
class DoublyLinkedNode {
public:
    DoublyLinkedNode *prev, *next;

    DoublyLinkedNode(int key, int value) : _key(key), _value(value), prev(nullptr), next(nullptr) {
    }

    int getKey() {
        return _key;
    }

    int getValue() {
        return _value;
    }

    void setValue(int value) {
        _value = value;
    }
private:
    int _key, _value;
};
