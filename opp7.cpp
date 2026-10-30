#include <iostream>
using namespace std;

// Real-life example: Financial calculator and unified payment gateway.
// Concepts: Compile-time polymorphism (function overloading) and
//           Run-time polymorphism (virtual functions, function overriding, base pointers).

// ==============================================================
// 1. COMPILE-TIME POLYMORPHISM (Function Overloading)
// ==============================================================
class Calculator {
public:
    // Overload 1: Two integer parameters
    int add(int a, int b) {
        return a + b;
    }

    // Overload 2: Two floating-point parameters (different parameter types)
    float add(float a, float b) {
        return a + b;
    }

    // Overload 3: Three integer parameters (different parameter count)
    int add(int a, int b, int c) {
        return a + b + c;
    }
};


// ==============================================================
// 2. RUN-TIME POLYMORPHISM (Function Overriding & Virtual Methods)
// ==============================================================
class Payment {
public:
    // Virtual function enables dynamic binding at runtime
    virtual void makePayment() {
        cout << "Processing payment..." << endl;
    }

    // Virtual destructor ensures complete cleanup in derived hierarchies
    virtual ~Payment() {
        cout << "Payment base destructor called" << endl;
    }
};

class UPI : public Payment {
public:
    void makePayment() override {
        cout << "Payment made using UPI." << endl;
    }

    ~UPI() override {
        cout << "UPI destructor called" << endl;
    }
};

class CreditCard : public Payment {
public:
    void makePayment() override {
        cout << "Payment made using Credit Card." << endl;
    }

    ~CreditCard() override {
        cout << "CreditCard destructor called" << endl;
    }
};


// ==============================================================
// MAIN FUNCTION
// ==============================================================
int main() {
    cout << "=== Demonstrating Polymorphism in C++ ===" << endl;

    // 1. Compile-Time Polymorphism
    cout << "\n--- Compile-Time Polymorphism (Function Overloading) ---" << endl;

    Calculator c;

    cout << "Addition of 2 integers (10 + 20)      : "
         << c.add(10, 20) << endl;

    cout << "Addition of 2 float numbers (5.5 + 4.5): "
         << c.add(5.5f, 4.5f) << endl;

    cout << "Addition of 3 integers (10 + 20 + 30)  : "
         << c.add(10, 20, 30) << endl;


    // 2. Run-Time Polymorphism
    cout << "\n--- Run-Time Polymorphism (Function Overriding) ---" << endl;

    {
        Payment *p = nullptr;

        UPI u;
        CreditCard cc;

        // Base pointer points to UPI derived object
        p = &u;
        p->makePayment();

        // Base pointer points to CreditCard derived object
        p = &cc;
        p->makePayment();

        cout << "\n[Leaving scope - Destructors called in reverse order]:" << endl;
    }

    return 0;
}
