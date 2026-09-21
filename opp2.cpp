#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    float marks;

public:
    // 1. Default Constructor
    Student()
    {
        name = "Unknown";
        rollNo = 0;
        marks = 0;

        cout << "\nDefault Constructor Called" << endl;
    }

    // 2. Parameterized Constructor
    Student(string n, int r, float m)
    {
        name = n;
        rollNo = r;
        marks = m;

        cout << "\nParameterized Constructor Called" << endl;
    }

    // 3. Copy Constructor
    Student(const Student &s)
    {
        name = s.name;
        rollNo = s.rollNo;
        marks = s.marks;

        cout << "\nCopy Constructor Called" << endl;
    }

    // Member function to display student details
    void display()
    {
        cout << "\n----- Student Details -----" << endl;
        cout << "Name    : " << name << endl;
        cout << "Roll No : " << rollNo << endl;
        cout << "Marks   : " << marks << endl;
    }

    // Member function to check result
    void checkResult()
    {
        if (marks >= 40)
            cout << "Result  : PASS" << endl;
        else
            cout << "Result  : FAIL" << endl;
    }

    // Member function to calculate grade
    void calculateGrade()
    {
        if (marks >= 90)
            cout << "Grade   : A+" << endl;
        else if (marks >= 80)
            cout << "Grade   : A" << endl;
        else if (marks >= 70)
            cout << "Grade   : B" << endl;
        else if (marks >= 60)
            cout << "Grade   : C" << endl;
        else if (marks >= 40)
            cout << "Grade   : D" << endl;
        else
            cout << "Grade   : F" << endl;
    }
};

int main()
{
    string name;
    int rollNo;
    float marks;

    // Taking input from user
    cout << "===== ENTER STUDENT DETAILS =====" << endl;

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    cout << "Enter Marks: ";
    cin >> marks;

    // ---------------- Parameterized Constructor ----------------
    Student s1(name, rollNo, marks);

    s1.display();
    s1.checkResult();
    s1.calculateGrade();

    // ---------------- Copy Constructor ----------------
    cout << "\n===== COPYING STUDENT OBJECT =====";

    Student s2(s1);

    s2.display();
    s2.checkResult();
    s2.calculateGrade();

    // ---------------- Default Constructor ----------------
    cout << "\n===== DEFAULT CONSTRUCTOR =====";

    Student s3;

    s3.display();

    cout << "\nProgram Ended." << endl;

    return 0;
}
