#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

// Class with copy constructor and move constructor
class Buffer {
    int *data;
    int size;

public:
    Buffer(int n) : data(new int[n]), size(n) {
        for (int i = 0; i < size; i++) {
            data[i] = i + 1;
        }

        cout << "Constructor: allocated "
             << size << " ints" << endl;
    }

    // Copy constructor
    Buffer(const Buffer &other)
        : data(new int[other.size]), size(other.size) {

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        cout << "Copy constructor: copied "
             << size << " ints" << endl;
    }

    // Move constructor
    Buffer(Buffer &&other) noexcept
        : data(other.data), size(other.size) {

        other.data = nullptr;
        other.size = 0;

        cout << "Move constructor: moved "
             << size << " ints (no copy)" << endl;
    }

    ~Buffer() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }
};

int main() {
    cout << "===== 1. std::move with string ====="
         << endl;

    string str1 = "Hello, C++ Programming";

    cout << "\nBefore moving:" << endl;
    cout << "str1 = " << str1 << endl;

    string str2 = std::move(str1);

    cout << "\nAfter moving:" << endl;
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    cout << "\n===== 2. std::move with vector ====="
         << endl;

    vector<int> v1 = {1, 2, 3, 4, 5};

    cout << "Before moving: v1.size() = "
         << v1.size() << endl;

    vector<int> v2 = std::move(v1);

    cout << "After moving: v1.size() = "
         << v1.size()
         << ", v2.size() = " << v2.size() << endl;

    cout << "\n===== 3. Copy constructor vs Move constructor ====="
         << endl;

    Buffer b1(5);

    Buffer b2 = b1;             // Copy constructor
    Buffer b3 = std::move(b1);  // Move constructor

    cout << "\nBuffer sizes after operations:" << endl;

    cout << "b1 size = " << b1.getSize() << endl;
    cout << "b2 size = " << b2.getSize() << endl;
    cout << "b3 size = " << b3.getSize() << endl;

    cout << "\nProgram ended successfully." << endl;

    return 0;
}
