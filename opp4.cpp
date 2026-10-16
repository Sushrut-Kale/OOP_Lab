#include <iostream>
#include <string>
using namespace std;

// Real-life data: one record per student
struct Student
{
    string name;
    int rollNumber;
    int marks;
};

int main()
{
    int n;
    cout << "=== Student Marks Management ===" << endl;
    cout << "Enter the number of students: ";
    cin >> n;

    // Validate input
    if (n <= 0)
    {
        cout << "Invalid number of students!" << endl;
        return 0;
    }

    // new[] : allocate an ARRAY of n Student records at runtime
    Student* students = new Student[n];

    // new : allocate a SINGLE object (class average)
    double* average = new double;

    // Input details of every student
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "  Enter name (single word): ";
        cin >> students[i].name;
        cout << "  Enter roll number: ";
        cin >> students[i].rollNumber;
        cout << "  Enter marks (out of 100): ";
        cin >> students[i].marks;
    }

    // Calculate total and find the topper
    int total = 0;
    int topperIndex = 0;
    for (int i = 0; i < n; i++)
    {
        total += students[i].marks;
        if (students[i].marks > students[topperIndex].marks)
            topperIndex = i;
    }

    // Store average in the dynamically allocated variable
    *average = static_cast<double>(total) / n;

    // Display report
    cout << "\n=== Student Report ===" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Roll " << students[i].rollNumber << " | "
             << students[i].name << " | Marks: "
             << students[i].marks << endl;
    }
    cout << "Total marks   : " << total << endl;
    cout << "Average marks : " << *average << endl;
    cout << "Topper        : " << students[topperIndex].name
         << " (" << students[topperIndex].marks << ")" << endl;

    // Release memory: delete[] for new[], delete for new
    delete[] students;
    delete average;

    // Avoid dangling pointers
    students = nullptr;
    average = nullptr;

    cout << "\nDynamic memory released successfully." << endl;
    return 0;
}
