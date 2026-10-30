#include <iostream>
using namespace std;

// Compile-time Polymorphism: Function Overloading
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

// Compile-time Polymorphism: Operator Overloading
class Complex {
    double real, imag;

public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i) {
    }

    Complex operator+(const Complex &other) const {
        return Complex(
            real + other.real,
            imag + other.imag
        );
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Runtime Polymorphism
class Shape {
public:
    virtual double area() const {
        return 0;
    }

    virtual void show() const {
        cout << "Generic Shape, Area = "
             << area() << endl;
    }

    virtual ~Shape() {
    }
};

class Circle : public Shape {
    double r;

public:
    Circle(double radius) : r(radius) {
    }

    double area() const override {
        return 3.14159 * r * r;
    }

    void show() const override {
        cout << "Circle (r = " << r
             << "), Area = " << area() << endl;
    }
};

class Rectangle : public Shape {
    double l, b;

public:
    Rectangle(double length, double breadth)
        : l(length), b(breadth) {
    }

    double area() const override {
        return l * b;
    }

    void show() const override {
        cout << "Rectangle (" << l << " x "
             << b << "), Area = " << area() << endl;
    }
};

class Triangle : public Shape {
    double base, height;

public:
    Triangle(double b, double h)
        : base(b), height(h) {
    }

    double area() const override {
        return 0.5 * base * height;
    }

    void show() const override {
        cout << "Triangle (b = " << base
             << ", h = " << height
             << "), Area = " << area() << endl;
    }
};

int main() {
    cout << "===== Compile-time Polymorphism =====" << endl;

    cout << "\n-- Function Overloading --" << endl;

    Calculator calc;

    cout << "add(10, 20) = "
         << calc.add(10, 20) << endl;

    cout << "add(2.5, 3.5) = "
         << calc.add(2.5, 3.5) << endl;

    cout << "add(1, 2, 3) = "
         << calc.add(1, 2, 3) << endl;

    cout << "\n-- Operator Overloading --" << endl;

    Complex c1(3, 4), c2(1, 2), c3;

    cout << "c1 = ";
    c1.display();

    cout << "c2 = ";
    c2.display();

    c3 = c1 + c2;

    cout << "c1 + c2 = ";
    c3.display();

    cout << "\n===== Runtime Polymorphism =====" << endl;

    Shape *shapes[4] = {
        new Shape(),
        new Circle(5),
        new Rectangle(4, 6),
        new Triangle(3, 8)
    };

    for (int i = 0; i < 4; i++) {
        shapes[i]->show();
    }

    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }

    return 0;
}
