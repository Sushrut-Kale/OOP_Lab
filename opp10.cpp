#include <iostream>
#include <string>
using namespace std;

// Function template: maximum()
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Function template: swapValues()
template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Function template with two types
template <typename T, typename U>
void showPair(T first, U second) {
    cout << "Pair: (" << first
         << ", " << second << ")" << endl;
}

// Class template: Calculator
template <class T>
class Calculator {
    T a, b;

public:
    Calculator(T x, T y) : a(x), b(y) {
    }

    T add() const {
        return a + b;
    }

    T subtract() const {
        return a - b;
    }

    T multiply() const {
        return a * b;
    }

    T divide() const {
        return a / b;
    }
};

// Class template: Stack
template <class T>
class Stack {
    T arr[10];
    int top;

public:
    Stack() : top(-1) {
    }

    void push(T value) {
        if (top == 9) {
            cout << "Stack overflow" << endl;
            return;
        }

        arr[++top] = value;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return T();
        }

        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    cout << "===== 1. Function template: maximum() ====="
         << endl;

    cout << "maximum(10, 20) = "
         << maximum(10, 20) << endl;

    cout << "maximum(3.5, 2.1) = "
         << maximum(3.5, 2.1) << endl;

    cout << "maximum('a', 'z') = "
         << maximum('a', 'z') << endl;

    cout << "maximum(\"apple\", \"banana\") = "
         << maximum(string("apple"), string("banana"))
         << endl;

    cout << "\n===== 2. Function template: swapValues() ====="
         << endl;

    int x = 5, y = 10;

    cout << "Before swap: x = " << x
         << ", y = " << y << endl;

    swapValues(x, y);

    cout << "After swap: x = " << x
         << ", y = " << y << endl;

    string s1 = "Hello", s2 = "World";

    cout << "\nBefore swap: s1 = " << s1
         << ", s2 = " << s2 << endl;

    swapValues(s1, s2);

    cout << "After swap: s1 = " << s1
         << ", s2 = " << s2 << endl;

    cout << "\n===== 3. Function template with two types ====="
         << endl;

    showPair(1, "Apple");
    showPair(2.5, 'A');

    cout << "\n===== 4. Class template: Calculator<T> ====="
         << endl;

    Calculator<int> ci(20, 4);

    cout << "Calculator<int>(20, 4):" << endl;
    cout << "add = " << ci.add() << endl;
    cout << "subtract = " << ci.subtract() << endl;
    cout << "multiply = " << ci.multiply() << endl;
    cout << "divide = " << ci.divide() << endl;

    Calculator<double> cd(7.5, 2.5);

    cout << "\nCalculator<double>(7.5, 2.5):" << endl;
    cout << "add = " << cd.add() << endl;
    cout << "subtract = " << cd.subtract() << endl;
    cout << "multiply = " << cd.multiply() << endl;
    cout << "divide = " << cd.divide() << endl;

    cout << "\n===== 5. Class template: Stack<T> ====="
         << endl;

    Stack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Popped: " << intStack.pop() << endl;
    cout << "Popped: " << intStack.pop() << endl;
    cout << "Popped: " << intStack.pop() << endl;

    if (intStack.isEmpty()) {
        cout << "Stack is empty" << endl;
    }

    return 0;
}
