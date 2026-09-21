# Problem Solving Using OOP (C++) – Lab Assignments

| | |
|---|---|
| **Name** | Sushrut Kale |
| **PRN** | 202501110147 |
| **Class / Batch** | SY B2 CSE (AIML) |
| **Subject** | Problem Solving Using OOP (C++) |
| **Repository** | https://github.com/Sushrut-Kale/OOP_Lab |

This repository contains the C++ programs for the first three practical assignments, along with how to compile them, sample input/output and a short summary of the concepts used.

---

## Repository Structure

```
.
├── opp1.cpp     # Assignment 1 – Constructor and Destructor
├── opp2.cpp     # Assignment 2 – Constructor Types
├── opp3.cpp     # Assignment 3 – Operator Overloading
└── readme.md
```

## Requirements

- A C++ compiler with C++11 or later (g++ / GCC, clang++ or MSVC)
- Any editor or IDE (Visual Studio Code was used)

## How to Compile and Run

```bash
# Assignment 1
g++ opp1.cpp -o opp1 && ./opp1

# Assignment 2
g++ opp2.cpp -o opp2 && ./opp2

# Assignment 3
g++ opp3.cpp -o opp3 && ./opp3
```

On Windows (PowerShell / CMD) run the executable as `opp1.exe` instead of `./opp1`.

---

## Assignment 1 – Classes, Objects, Constructor and Destructor

**File:** `opp1.cpp`

**Problem statement:** Create a class `Student` with the data members name, roll number and marks. Use a constructor to initialise the object, member functions to accept and display the data, and a destructor that runs when the object is destroyed. Demonstrate the order in which constructors and destructors are called.

**Concepts used:**

- Class and object, encapsulation (private data, public member functions)
- Constructor – called automatically when an object is created
- Destructor (`~Student()`) – called automatically when an object goes out of scope
- Destructors run in the reverse order of construction (shown with an inner block)

**Sample run:**

```
Constructor called.
Enter Student Name: Sushrut Kale
Enter Roll Number: 101
Enter Marks: 88.5

--- Student Details ---
Name: Sushrut Kale
Roll Number: 101
Marks: 88.5

[Entering inner block]
Constructor called.

--- Student Details ---
Name: Unknown
Roll Number: 0
Marks: 0
[Leaving inner block]

Destructor called for Unknown.

Destructor called for Sushrut Kale.
```

---

## Assignment 2 – Constructor Types

**File:** `opp2.cpp`

**Problem statement:** Implement various types of constructors and member functions. A `Student` class (name, roll number, marks) has a default, a parameterized and a copy constructor, together with functions to display the details, check the result and calculate the grade.

**Concepts used:**

- Default constructor – `Student()`
- Parameterized constructor – `Student(string n, int r, float m)`
- Copy constructor – `Student(const Student &s)` (the argument is passed by reference)
- Constructor overloading
- `if–else` ladder for result and grade

**Result and grade rules:**

| Marks | Grade |
|---|---|
| 90 and above | A+ |
| 80 – 89 | A |
| 70 – 79 | B |
| 60 – 69 | C |
| 40 – 59 | D |
| below 40 | F |

Result is **PASS** if marks ≥ 40, otherwise **FAIL**.

**Sample run:**

```
===== ENTER STUDENT DETAILS =====
Enter Name: Sushrut Kale
Enter Roll Number: 101
Enter Marks: 88.5

Parameterized Constructor Called

----- Student Details -----
Name    : Sushrut Kale
Roll No : 101
Marks   : 88.5
Result  : PASS
Grade   : A

===== COPYING STUDENT OBJECT =====
Copy Constructor Called

----- Student Details -----
Name    : Sushrut Kale
Roll No : 101
Marks   : 88.5
Result  : PASS
Grade   : A

===== DEFAULT CONSTRUCTOR =====
Default Constructor Called

----- Student Details -----
Name    : Unknown
Roll No : 0
Marks   : 0

Program Ended.
```

---

## Assignment 3 – Operator Overloading

**File:** `opp3.cpp`

**Problem statement:** Write a program on operator overloading using default and parameterized constructors. A `Complex` class overloads the `+`, `-` and `*` operators so that two complex numbers can be added, subtracted and multiplied like built-in types.

**Concepts used:**

- Operator overloading as member functions (`c1 + c2` is interpreted as `c1.operator+(c2)`)
- Default constructor (creates `0 + 0i`) and parameterized constructor
- Returning a new object from an operator function

**Formulas:**

```
(a + bi) + (c + di) = (a + c) + (b + d)i
(a + bi) - (c + di) = (a - c) + (b - d)i
(a + bi) * (c + di) = (ac - bd) + (ad + bc)i
```

**Sample run:**

```
===== COMPLEX NUMBER OPERATIONS =====

Enter real part of first complex number: 2
Enter imaginary part of first complex number: 3

Enter real part of second complex number: 4
Enter imaginary part of second complex number: 5

Default Object (c0)    : 0 + 0i
First Complex Number   : 2 + 3i
Second Complex Number  : 4 + 5i

After Addition (+)       : 6 + 8i
After Subtraction (-)    : -2 - 2i
After Multiplication (*) : -7 + 22i
```

---

## Test Summary

| Assignment | Test | Input | Result |
|---|---|---|---|
| 1 | Constructor and data display | Sushrut Kale, 101, 88.5 | Pass |
| 1 | Default values from constructor | Aarav Patil, 7, 92 | Pass |
| 1 | Order of destructor calls | Riya Sharma, 215, 35 | Pass |
| 2 | Parameterized constructor, pass case | Sushrut Kale, 101, 88.5 | Pass (Grade A) |
| 2 | Boundary value, fail case | Aarav Patil, 7, 39 | Pass (FAIL, Grade F) |
| 2 | All three constructors, top grade | Riya Sharma, 215, 95 | Pass (Grade A+) |
| 3 | Positive parts | (2+3i), (4+5i) | Pass |
| 3 | Negative imaginary part | (5-2i), (3+4i) | Pass |
| 3 | Decimal and negative values | (-1.5+2.5i), (1-1i) | Pass |

## Notes

- Names with spaces are read using `getline(cin, name)`, so the full name can be entered.
- All programs were compiled with `g++ -Wall -Wextra` without warnings.
