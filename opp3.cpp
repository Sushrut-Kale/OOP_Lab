#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    // Default Constructor
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Parameterized Constructor
    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }

    // Overloading + operator
    Complex operator+(Complex c)
    {
        Complex temp;

        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }

    // Overloading - operator
    Complex operator-(Complex c)
    {
        Complex temp;

        temp.real = real - c.real;
        temp.imag = imag - c.imag;

        return temp;
    }

    // Overloading * operator: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    Complex operator*(Complex c)
    {
        Complex temp;

        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);

        return temp;
    }

    // Member function to display complex number
    void display()
    {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main()
{
    float r1, i1, r2, i2;

    cout << "===== COMPLEX NUMBER OPERATIONS =====" << endl;

    // Taking input for first complex number
    cout << "\nEnter real part of first complex number: ";
    cin >> r1;

    cout << "Enter imaginary part of first complex number: ";
    cin >> i1;

    // Taking input for second complex number
    cout << "\nEnter real part of second complex number: ";
    cin >> r2;

    cout << "Enter imaginary part of second complex number: ";
    cin >> i2;

    // Creating objects using default and parameterized constructors
    Complex c0;
    Complex c1(r1, i1);
    Complex c2(r2, i2);

    cout << "\nDefault Object (c0)    : ";
    c0.display();

    cout << "First Complex Number   : ";
    c1.display();

    cout << "Second Complex Number  : ";
    c2.display();

    // Operator overloading
    Complex sum  = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "\nAfter Addition (+)       : ";
    sum.display();

    cout << "After Subtraction (-)    : ";
    diff.display();

    cout << "After Multiplication (*) : ";
    prod.display();

    return 0;
}
