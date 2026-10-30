# Problem Solving Using OOP (C++) – Lab Assignments

| | |
|---|---|
| **Name** | Sushrut Kale |
| **PRN** | 202501110147 |
| **Class / Batch** | SY B2 CSE (AIML) |
| **Subject** | Problem Solving Using OOP (C++) |
| **Repository** | https://github.com/Sushrut-Kale/OOP_Lab |

This repository contains the C++ programs for the practical assignments, along with how to compile them, sample input/output and a short summary of the concepts used.

---

## Repository Structure

```
.
├── opp1.cpp     # Assignment 1 – Constructor and Destructor
├── opp2.cpp     # Assignment 2 – Constructor Types
├── opp3.cpp     # Assignment 3 – Operator Overloading
├── opp4.cpp     # Assignment 4 – Dynamic Memory Allocation (new & delete)
├── opp5.cpp     # Assignment 5 – this Pointer, Inline & Static Members, Friend Class
├── opp6.cpp     # Assignment 6 – Types of Inheritance in C++
├── opp7.cpp     # Assignment 7 – Polymorphism (Compile-Time and Run-Time)
├── opp8.cpp     # Assignment 8 – Exception Handling (try, throw, catch)
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

# Assignment 4
g++ opp4.cpp -o opp4 && ./opp4

# Assignment 5
g++ opp5.cpp -o opp5 && ./opp5

# Assignment 6
g++ opp6.cpp -o opp6 && ./opp6

# Assignment 7
g++ opp7.cpp -o opp7 && ./opp7

# Assignment 8
g++ opp8.cpp -o opp8 && ./opp8
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

## Assignment 4 – Dynamic Memory Allocation

**File:** `opp4.cpp`

**Problem statement:** Write a program to manage student marks using dynamic memory allocation in C++. Allocate an array of `Student` records at runtime based on user input using `new[]`, and allocate a single variable for calculating class average using `new`. Calculate the total marks, find the class topper, display a student report, and release all dynamically allocated memory using `delete[]` and `delete` while setting pointers to `nullptr` to avoid dangling pointers.

**Concepts used:**

- Dynamic memory allocation on the heap: `new` (single object) and `new[]` (array of objects)
- Deallocation: `delete` (single object) and `delete[]` (array of objects)
- Pointer hygiene: avoiding dangling pointers (`students = nullptr; average = nullptr;`)
- Structure `struct Student` holding student data members (`name`, `rollNumber`, `marks`)
- Runtime array sizing based on user input with input validation (`n <= 0`)
- Type casting with `static_cast<double>` for accurate floating-point average calculation

**Sample run:**

```
=== Student Marks Management ===
Enter the number of students: 2

Student 1
  Enter name (single word): Sushrut
  Enter roll number: 101
  Enter marks (out of 100): 88

Student 2
  Enter name (single word): Aarav
  Enter roll number: 102
  Enter marks (out of 100): 95

=== Student Report ===
Roll 101 | Sushrut | Marks: 88
Roll 102 | Aarav | Marks: 95
Total marks   : 183
Average marks : 91.5
Topper        : Aarav (95)

Dynamic memory released successfully.
```

---

## Assignment 5 – This Pointer, Inline & Static Members, and Friend Class

**File:** `opp5.cpp`

**Problem statement:** Implement a bank account management system demonstrating core object-oriented programming concepts in C++:
- The `this` pointer for resolving naming ambiguity between member variables and parameters, as well as enabling method chaining (`acc.deposit(2000).withdraw(500)`).
- Inline functions defined implicitly inside the class body (`getBalance()`) and explicitly outside the class (`display()`).
- Static data members (`totalAccounts`) shared across all instances and static member functions (`getTotalAccounts()`) accessible without an object.
- A friend class (`Auditor`) that accesses private members of `BankAccount` to inspect account state and apply interest.

**Concepts used:**

- `this` pointer: Differentiates object data members from constructor arguments and allows method chaining by returning `*this` (reference to calling object).
- Static data members: `static int totalAccounts` maintains a single copy across all objects, incremented on construction and decremented on destruction.
- Static member functions: `getTotalAccounts()` callable directly using class scope (`BankAccount::getTotalAccounts()`).
- Inline functions: Eliminates function call overhead for small frequently-called functions (`inline void display() const`).
- Friend class: `friend class Auditor` allows `Auditor` methods direct access to private members (`holderName`, `accountNumber`, `balance`).

**Sample run:**

```
=== Bank Account Management ===
Accounts at start: 0
Accounts after opening: 2

--- Initial details ---
Account No: 1001 | Holder: Sushrut | Balance: Rs. 5000
Account No: 1002 | Holder: Rahul | Balance: Rs. 8000

--- Transactions (chained calls) ---
Insufficient balance for Rahul!
Account No: 1001 | Holder: Sushrut | Balance: Rs. 6800
Account No: 1002 | Holder: Rahul | Balance: Rs. 8000

--- Auditor (friend class) ---
[Audit] Sushrut (A/C 1001) has Rs. 6800
[Audit] Rahul (A/C 1002) has Rs. 8000
After 4% interest, balance of Sushrut: Rs. 7072

Total accounts: 2
```

---

## Assignment 6 – Types of Inheritance in C++

**File:** `opp6.cpp`

**Problem statement:** Implement a comprehensive C++ program demonstrating all six types of inheritance:
- **Single Inheritance:** A derived class inheriting from a single base class (`Student` derived from `Person`).
- **Multiple Inheritance:** A derived class inheriting from more than one base class (`Result` derived from `Academics` and `Sports`).
- **Multilevel Inheritance:** A class hierarchy spanning three levels (`Director` derived from `Manager`, which derives from `Employee`).
- **Hierarchical Inheritance:** Multiple derived classes inheriting from a common base class (`Dog` and `Cat` derived from `Animal`).
- **Hybrid Inheritance:** A combination of two or more distinct inheritance types (`ScoreCard` combining multilevel inheritance from `StudentData` -> `TestMarks` and multiple inheritance with `Extracurricular`).
- **Multipath Inheritance:** A diamond inheritance structure (`UniversityMember` -> `Faculty` & `Researcher` -> `Professor`) resolved without ambiguity using `virtual` base classes.

**Concepts used:**

- Access specifiers (`protected`, `public`) and constructor member initializer lists (`Base(args)`).
- Destructor invocation order (derived destructors run before base destructors).
- The Diamond Problem: Ambiguity and duplicated base class subobjects caused by multiple inheritance paths from a common base class.
- Virtual Base Classes (`virtual public Base`): Ensures that only a single shared instance of the base class is inherited by the most-derived class.
- Most-derived class responsibility: The most-derived class (`Professor`) directly initializes the virtual base class (`UniversityMember`).

**Sample run:**

```
=== Demonstrating All 6 Types of Inheritance in C++ ===

--- 1. Single Inheritance ---
Name: Rahul
Role: Student
Student destructor called for Rahul
Person destructor called for Rahul

--- 2. Multiple Inheritance ---
Academic Marks: 85
Sports Score: 90
Total Score: 175

--- 3. Multilevel Inheritance ---
Employee Name: Amit
Department: Operations
Designation: Managing Director

--- 4. Hierarchical Inheritance ---
Animal eats food
Dog barks
Animal eats food
Cat meows

--- 5. Hybrid Inheritance ---
Roll Number: 101
Part 1 Marks: 45
Part 2 Marks: 48
Extracurricular Score: 18
Grand Total: 111

--- 6. Multipath Inheritance (Diamond Problem) ---
Professor Name: Dr. Sharma
University: MIT Pune
Department: Computer Science
Research Area: Artificial Intelligence
```

---

## Assignment 7 – Polymorphism (Compile-Time and Run-Time)

**File:** `opp7.cpp`

**Problem statement:** Implement a C++ program demonstrating both forms of polymorphism:
- **Compile-Time Polymorphism (Static Binding):** Function overloading in a `Calculator` class providing multiple definitions of `add()` differing in parameter count (2 integers vs 3 integers) and parameter types (`int` vs `float`), resolved at compile time.
- **Run-Time Polymorphism (Dynamic Binding):** Function overriding using a base class `Payment` with a `virtual void makePayment()` function and a `virtual` destructor, overridden in derived classes `UPI` and `CreditCard`. Base class pointers (`Payment*`) dynamically dispatch calls to the appropriate derived class method at runtime based on the actual object being pointed to.

**Concepts used:**

- Static binding / early binding: Compiler selects the overloaded function based on argument types and count.
- Dynamic binding / late binding: Virtual function mechanism with dynamic dispatch via virtual method table (`vptr`/`vtbl`).
- Keywords `virtual` and `override`: `virtual` enables polymorphic behavior; `override` guarantees compile-time verification of signature compatibility.
- Virtual destructors: Ensures derived class destructors are properly invoked when objects are managed through base class pointers.
- Unified interface: Manipulating multiple heterogeneous derived objects through a common base pointer (`Payment*`).

**Sample run:**

```
=== Demonstrating Polymorphism in C++ ===

--- Compile-Time Polymorphism (Function Overloading) ---
Addition of 2 integers (10 + 20)      : 30
Addition of 2 float numbers (5.5 + 4.5): 10
Addition of 3 integers (10 + 20 + 30)  : 60

--- Run-Time Polymorphism (Function Overriding) ---
Payment made using UPI.
Payment made using Credit Card.

[Leaving scope - Destructors called in reverse order]:
CreditCard destructor called
Payment base destructor called
UPI destructor called
Payment base destructor called
```

---

## Assignment 8 – Exception Handling in C++

**File:** `opp8.cpp`

**Problem statement:** Implement a bank account management system demonstrating robust runtime exception handling using `try`, `throw`, and `catch` blocks with standard exceptions (`std::invalid_argument` and `std::runtime_error`):
- Throw `std::invalid_argument` if the withdrawal amount entered is zero or negative (`amount <= 0`).
- Throw `std::runtime_error` if the withdrawal amount exceeds the current account balance (`amount > balance`).
- Catch both exceptions by reference (`const exception&`), display descriptive error messages using `.what()`, and ensure the account balance remains consistent and unaffected by rejected transactions.

**Concepts used:**

- Exception handling mechanism (`try`, `throw`, `catch`).
- Standard exception hierarchy from `<stdexcept>`:
  - `std::invalid_argument`: Derived from `std::logic_error` representing invalid input arguments.
  - `std::runtime_error`: Represents errors detectable only at execution time.
- Exception object inspection using member function `e.what()`.
- State consistency: Ensuring transactions are atomic (balance is only modified upon full validation).
- Destructor cleanup on normal termination or scope exit.

**Sample runs:**

**Case 1: Successful Withdrawal**
```
===== BANKING SYSTEM =====
Current Balance: Rs. 5000

Enter amount to withdraw: Rs. 2000
Withdrawal Successful!
Withdrawn Amount: Rs. 2000
Remaining Balance: Rs. 3000

Final Account Details:
Current Balance: Rs. 3000
Bank Account Object Destroyed.
```

**Case 2: Invalid Amount (Zero / Negative)**
```
===== BANKING SYSTEM =====
Current Balance: Rs. 5000

Enter amount to withdraw: Rs. -500
Exception: Invalid amount! Enter a positive amount.

Final Account Details:
Current Balance: Rs. 5000
Bank Account Object Destroyed.
```

**Case 3: Insufficient Balance**
```
===== BANKING SYSTEM =====
Current Balance: Rs. 5000

Enter amount to withdraw: Rs. 8000
Exception: Insufficient balance! Withdrawal denied.

Final Account Details:
Current Balance: Rs. 5000
Bank Account Object Destroyed.
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
| 4 | Array allocation & topper calculation | 2 students: Sushrut (88), Aarav (95) | Pass (Topper Aarav) |
| 4 | Input validation for invalid count | n = 0 | Pass (Invalid number of students!) |
| 4 | Memory deallocation | new[], new, delete[], delete | Pass (Memory freed, pointers nulled) |
| 5 | Method chaining via this pointer | acc1.deposit(2000).withdraw(500).deposit(300) | Pass (Balance Rs. 6800) |
| 5 | Insufficient balance validation | Rahul withdraws 10000 with balance 8000 | Pass (Error message shown) |
| 5 | Static member tracking | Account creation & deletion count | Pass (0 -> 2 -> 2) |
| 5 | Friend class access & interest calculation | Auditor audits & adds 4% interest | Pass (Direct access to private fields, balance Rs. 7072) |
| 6 | Single inheritance & destructor order | Student Rahul | Pass (Base & derived displayed, destructors in reverse) |
| 6 | Multiple inheritance score aggregation | Academics 85, Sports 90 | Pass (Total score 175 calculated) |
| 6 | Multilevel hierarchy across 3 tiers | Director Amit, Operations | Pass (Employee -> Manager -> Director verified) |
| 6 | Hierarchical inheritance | Animal eats, Dog barks, Cat meows | Pass (Distinct derived behaviors from shared base) |
| 6 | Hybrid inheritance (Multilevel + Multiple) | ScoreCard Roll 101, 45, 48, 18 | Pass (Grand total 111 verified) |
| 6 | Multipath inheritance (Diamond problem) | Professor Dr. Sharma, MIT Pune | Pass (Virtual base class prevents duplicate UniversityMember) |
| 7 | Function overloading by parameter count | add(10, 20) vs add(10, 20, 30) | Pass (Sum 30 and 60 calculated) |
| 7 | Function overloading by parameter type | add(5.5f, 4.5f) vs add(int, int) | Pass (Float addition 10 calculated) |
| 7 | Run-time dispatch via base pointer (UPI) | Payment* -> UPI object | Pass ("Payment made using UPI.") |
| 7 | Run-time dispatch via base pointer (CreditCard) | Payment* -> CreditCard object | Pass ("Payment made using Credit Card.") |
| 7 | Virtual destructor invocation | UPI & CreditCard destructors | Pass (Derived and base destructors invoked cleanly in reverse) |
| 8 | Valid withdrawal transaction | Withdrawal amount Rs. 2000 from Rs. 5000 | Pass (Balance updated to Rs. 3000) |
| 8 | Zero or negative amount validation | Withdrawal amount Rs. -500 | Pass (invalid_argument caught, balance unchanged) |
| 8 | Insufficient balance validation | Withdrawal amount Rs. 8000 from Rs. 5000 | Pass (runtime_error caught, balance unchanged) |
| 8 | Object destruction and state consistency | Destructor on exit | Pass (Bank Account Object Destroyed) |

## Notes

- Names with spaces are read using `getline(cin, name)`, so the full name can be entered.
- All programs were compiled with `g++ -Wall -Wextra` without warnings.
