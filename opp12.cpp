#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show()" << endl;
    }

    virtual ~Base() {
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show()" << endl;
    }

    void derivedOnly() {
        cout << "Derived-only function called" << endl;
    }
};

int main() {

    // ============= 1. static_cast =============

    cout << "===== 1. static_cast =====" << endl;

    int a = 7, b = 2;

    cout << "Without cast : 7 / 2 = "
         << (a / b) << endl;

    cout << "With cast    : 7 / 2 = "
         << static_cast<double>(a) / b << endl;

    double d = 9.99;

    int i = static_cast<int>(d);

    cout << "double 9.99 to int : "
         << i << endl;

    char ch = 'A';

    cout << "char 'A' to int : "
         << static_cast<int>(ch) << endl;

    int n = 97;

    cout << "int 97 to char : "
         << static_cast<char>(n) << endl;

    Derived obj;

    Base *basePtr = &obj;

    Derived *dPtr = static_cast<Derived*>(basePtr);

    // Downcast in the same hierarchy
    dPtr->derivedOnly();


    // ============= 2. dynamic_cast =============

    cout << "\n===== 2. dynamic_cast =====" << endl;

    Base *b1 = new Derived();

    // Base pointer holding a Derived object
    Base *b2 = new Base();

    // Successful dynamic cast
    Derived *d1 = dynamic_cast<Derived*>(b1);

    if (d1 != NULL) {
        cout << "Cast of b1 succeeded: ";
        d1->derivedOnly();
    }
    else {
        cout << "Cast of b1 failed" << endl;
    }

    // Failed dynamic cast
    Derived *d2 = dynamic_cast<Derived*>(b2);

    if (d2 != NULL) {
        cout << "Cast of b2 succeeded" << endl;
    }
    else {
        cout << "Cast of b2 failed: dynamic_cast returned NULL"
             << endl;
    }

    // Reference dynamic_cast
    try {
        Base &ref = *b1;

        Derived &derivedRef =
            dynamic_cast<Derived&>(ref);

        cout << "Reference cast succeeded: ";
        derivedRef.derivedOnly();
    }
    catch (const bad_cast &e) {
        cout << "Reference cast failed: "
             << e.what() << endl;
    }

    delete b1;
    delete b2;


    // ============= 3. const_cast =============

    cout << "\n===== 3. const_cast =====" << endl;

    int value = 50;

    const int *constPtr = &value;

    cout << "Original value = "
         << *constPtr << endl;

    int *modifiedPtr =
        const_cast<int*>(constPtr);

    *modifiedPtr = 100;

    cout << "Modified value = "
         << value << endl;


    // ============= 4. reinterpret_cast =============

    cout << "\n===== 4. reinterpret_cast =====" << endl;

    int num = 65;

    int *intPtr = &num;

    char *charPtr =
        reinterpret_cast<char*>(intPtr);

    cout << "Integer value = " << num << endl;

    cout << "First byte as character = "
         << *charPtr << endl;

    cout << "\nProgram ended successfully." << endl;

    return 0;
}
