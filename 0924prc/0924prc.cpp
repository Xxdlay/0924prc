#include <iostream>
#include <exception>

using namespace std;

class DynamicCharStack {
private:
    char* _data;
    int _top;
    int _capacity;

public:
    DynamicCharStack(int initialCapacity = 2) {
        if (initialCapacity <= 0) {
            throw invalid_argument("Invalid capacity");
        }
        _capacity = initialCapacity;
        _data = new char[_capacity];
        _top = -1;
    }

    ~DynamicCharStack() {
        delete[] _data;
    }

    void Push(char val) {
        if (_top >= _capacity - 1) {
            int newCapacity = _capacity * 2;
            char* newData = nullptr;
            try {
                newData = new char[newCapacity];
            }
            catch (const bad_alloc& e) {
                throw;
            }
            for (int i = 0; i <= _top; i++) {
                newData[i] = _data[i];
            }
            delete[] _data;
            _data = newData;
            _capacity = newCapacity;
        }
        _top++;
        _data[_top] = val;
    }

    char Pop() {
        if (_top == -1) {
            throw underflow_error("Stack underflow");
        }
        char val = _data[_top];
        _top--;
        return val;
    }

    char Peek() const {
        if (_top == -1) {
            throw underflow_error("Stack is empty");
        }
        return _data[_top];
    }

    bool IsEmpty() const {
        return _top == -1;
    }

    void Clear() {
        _top = -1;
    }
};