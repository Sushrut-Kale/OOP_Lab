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
    // Constructor: called automatically when an object is created
    Student()
    {
        name = "Unknown";
        rollNo = 0;
        marks = 0;

        cout << "Constructor called." << endl;
    }

    // Member function to accept student data
    void getData()
    {
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Member function to display student data
    void displayData()
    {
        cout << "\n--- Student Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }

    // Destructor: called automatically when an object is destroyed
    ~Student()
    {
        cout << "\nDestructor called for " << name << "." << endl;
    }
};

int main()
{
    Student s1;

    s1.getData();
    s1.displayData();

    // Object with limited scope to show the order of destruction
    {
        cout << "\n[Entering inner block]" << endl;
        Student temp;
        temp.displayData();
        cout << "[Leaving inner block]" << endl;
    }

    return 0;
}
