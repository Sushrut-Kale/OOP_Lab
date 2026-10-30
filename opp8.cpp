#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Custom Exception Class
class InvalidMarksException {
    int marks;

public:
    InvalidMarksException(int m) : marks(m) {
    }

    void show() const {
        cout << "Invalid marks entered: " << marks
             << " (must be between 0 and 100)"
             << endl;
    }
};

// Functions that throw exceptions
void checkAge(int age) {
    if (age < 18) {
        throw age;
    }

    cout << "Access granted. Age is "
         << age << endl;
}

int divide(int a, int b) {
    if (b == 0) {
        throw string("Division by zero is not allowed");
    }

    return a / b;
}

void validateMarks(int marks) {
    if (marks < 0 || marks > 100) {
        throw InvalidMarksException(marks);
    }

    cout << "Marks " << marks
         << " are valid" << endl;
}

int getElement(const int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range(
            "Index " + to_string(index) + " is out of range"
        );
    }

    return arr[index];
}

// Re-throwing an exception
void innerFunction() {
    try {
        throw runtime_error("Error occurred in inner function");
    }
    catch (const runtime_error &e) {
        cout << "Inner catch: " << e.what() << endl;
        throw;
    }
}

int main() {
    cout << "===== 1. try, throw and catch (int) ====="
         << endl;

    try {
        checkAge(20);
    }
    catch (int myNum) {
        cout << "Access denied. Age is " << myNum
             << " (must be 18 or above)" << endl;
    }

    try {
        checkAge(15);
    }
    catch (int myNum) {
        cout << "Access denied. Age is " << myNum
             << " (must be 18 or above)" << endl;
    }

    cout << "\n===== 2. Throwing a string =====" << endl;

    try {
        int r1 = divide(10, 2);
        cout << "10 / 2 = " << r1 << endl;

        int r2 = divide(10, 0);
        cout << "10 / 0 = " << r2 << endl;

        cout << "This line is never executed" << endl;
    }
    catch (const string &msg) {
        cout << "Exception caught: " << msg << endl;
    }

    cout << "\n===== 3. Custom exception class ====="
         << endl;

    try {
        validateMarks(85);
        validateMarks(120);
    }
    catch (const InvalidMarksException &e) {
        e.show();
    }

    cout << "\n===== 4. Standard exception (out_of_range) ====="
         << endl;

    int arr[3] = {10, 20, 30};

    try {
        int v1 = getElement(arr, 3, 1);
        cout << "arr[1] = " << v1 << endl;

        int v2 = getElement(arr, 3, 5);
        cout << "arr[5] = " << v2 << endl;
    }
    catch (const exception &e) {
        cout << "Exception caught: "
             << e.what() << endl;
    }

    cout << "\n===== 5. Re-throwing an exception ====="
         << endl;

    try {
        innerFunction();
    }
    catch (const exception &e) {
        cout << "Outer catch: " << e.what() << endl;
    }

    cout << "\n===== 6. Multiple catch blocks and catch-all ====="
         << endl;

    try {
        throw 3.14;
    }
    catch (int) {
        cout << "Integer exception caught" << endl;
    }
    catch (string) {
        cout << "String exception caught" << endl;
    }
    catch (...) {
        cout << "Unknown (default) exception caught"
             << endl;
    }

    cout << "\nProgram ended normally." << endl;

    return 0;
}
