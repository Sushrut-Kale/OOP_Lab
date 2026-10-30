#include <iostream>
#include <string>
using namespace std;

// Real-life example: Academic, organizational, and university hierarchy models.
// Concepts: Single, Multiple, Multilevel, Hierarchical, Hybrid, and Multipath Inheritance
//           (including Virtual Base Classes to resolve the Diamond Problem).

// ==============================================================
// 1. SINGLE INHERITANCE (Base -> Derived)
// ==============================================================
class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {}

    void showPerson() {
        cout << "Name: " << name << endl;
    }

    ~Person() {
        cout << "Person destructor called for " << name << endl;
    }
};

class Student : public Person {
public:
    Student(string n) : Person(n) {}

    void showStudent() {
        cout << "\n--- 1. Single Inheritance ---" << endl;
        showPerson();
        cout << "Role: Student" << endl;
    }

    ~Student() {
        cout << "Student destructor called for " << name << endl;
    }
};


// ==============================================================
// 2. MULTIPLE INHERITANCE (Base1, Base2 -> Derived)
// ==============================================================
class Academics {
public:
    int marks;

    Academics(int m) : marks(m) {}

    void showMarks() {
        cout << "Academic Marks: " << marks << endl;
    }
};

class Sports {
public:
    int score;

    Sports(int s) : score(s) {}

    void showScore() {
        cout << "Sports Score: " << score << endl;
    }
};

class Result : public Academics, public Sports {
public:
    Result(int m, int s) : Academics(m), Sports(s) {}

    void showResult() {
        cout << "\n--- 2. Multiple Inheritance ---" << endl;
        showMarks();
        showScore();
        cout << "Total Score: " << marks + score << endl;
    }
};


// ==============================================================
// 3. MULTILEVEL INHERITANCE (Base -> Intermediate -> Derived)
// ==============================================================
class Employee {
protected:
    string empName;

public:
    Employee(string n) : empName(n) {}

    void showEmployee() {
        cout << "Employee Name: " << empName << endl;
    }
};

class Manager : public Employee {
protected:
    string department;

public:
    Manager(string n, string dept) : Employee(n), department(dept) {}

    void showManager() {
        showEmployee();
        cout << "Department: " << department << endl;
    }
};

class Director : public Manager {
public:
    Director(string n, string dept) : Manager(n, dept) {}

    void showDirector() {
        cout << "\n--- 3. Multilevel Inheritance ---" << endl;
        showManager();
        cout << "Designation: Managing Director" << endl;
    }
};


// ==============================================================
// 4. HIERARCHICAL INHERITANCE (Base -> Derived1, Derived2)
// ==============================================================
class Animal {
public:
    void eat() {
        cout << "Animal eats food" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows" << endl;
    }
};


// ==============================================================
// 5. HYBRID INHERITANCE (Combination of Multilevel and Multiple)
// ==============================================================
class StudentData {
protected:
    int rollNo;

public:
    StudentData(int r) : rollNo(r) {}

    void showRoll() {
        cout << "Roll Number: " << rollNo << endl;
    }
};

class TestMarks : public StudentData {
protected:
    int part1, part2;

public:
    TestMarks(int r, int m1, int m2) : StudentData(r), part1(m1), part2(m2) {}

    void showTestMarks() {
        showRoll();
        cout << "Part 1 Marks: " << part1 << endl;
        cout << "Part 2 Marks: " << part2 << endl;
    }
};

class Extracurricular {
protected:
    int activityScore;

public:
    Extracurricular(int score) : activityScore(score) {}

    void showActivity() {
        cout << "Extracurricular Score: " << activityScore << endl;
    }
};

class ScoreCard : public TestMarks, public Extracurricular {
public:
    ScoreCard(int r, int m1, int m2, int score)
        : TestMarks(r, m1, m2), Extracurricular(score) {}

    void showScoreCard() {
        cout << "\n--- 5. Hybrid Inheritance ---" << endl;
        showTestMarks();
        showActivity();
        cout << "Grand Total: " << (part1 + part2 + activityScore) << endl;
    }
};


// ==============================================================
// 6. MULTIPATH INHERITANCE (Diamond problem resolved via 'virtual')
// ==============================================================
class UniversityMember {
protected:
    string universityName;

public:
    UniversityMember(string uName) : universityName(uName) {}

    void showUniversity() {
        cout << "University: " << universityName << endl;
    }
};

// Virtual inheritance ensures only one copy of UniversityMember is shared
class Faculty : virtual public UniversityMember {
protected:
    string department;

public:
    Faculty(string uName, string dept)
        : UniversityMember(uName), department(dept) {}

    void showFaculty() {
        cout << "Department: " << department << endl;
    }
};

class Researcher : virtual public UniversityMember {
protected:
    string researchArea;

public:
    Researcher(string uName, string area)
        : UniversityMember(uName), researchArea(area) {}

    void showResearch() {
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Faculty, public Researcher {
    string profName;

public:
    // Most-derived class calls the virtual base class constructor
    Professor(string uName, string dept, string area, string pName)
        : UniversityMember(uName), Faculty(uName, dept), Researcher(uName, area), profName(pName) {}

    void showProfessor() {
        cout << "\n--- 6. Multipath Inheritance (Diamond Problem) ---" << endl;
        cout << "Professor Name: " << profName << endl;
        showUniversity(); // No ambiguity because UniversityMember is virtual
        showFaculty();
        showResearch();
    }
};


// ==============================================================
// MAIN FUNCTION
// ==============================================================
int main() {
    cout << "=== Demonstrating All 6 Types of Inheritance in C++ ===" << endl;

    // 1. Single Inheritance (wrapped in block to demonstrate destructors)
    {
        Student s("Rahul");
        s.showStudent();
    }

    // 2. Multiple Inheritance
    Result r(85, 90);
    r.showResult();

    // 3. Multilevel Inheritance
    Director dir("Amit", "Operations");
    dir.showDirector();

    // 4. Hierarchical Inheritance
    cout << "\n--- 4. Hierarchical Inheritance ---" << endl;
    Dog d;
    d.eat();
    d.bark();

    Cat c;
    c.eat();
    c.meow();

    // 5. Hybrid Inheritance
    ScoreCard sc(101, 45, 48, 18);
    sc.showScoreCard();

    // 6. Multipath Inheritance
    Professor prof("MIT Pune", "Computer Science", "Artificial Intelligence", "Dr. Sharma");
    prof.showProfessor();

    return 0;
}

