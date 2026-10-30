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
├── opp9.cpp     # Assignment 9 – std::move() and Move Semantics
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

# Assignment 9
g++ -std=c++11 opp9.cpp -o opp9 && ./opp9
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

## Assignment 6 – Different Types of Inheritance

**File:** `opp6.cpp`

**Problem statement:** Implement a C++ program demonstrating core types of inheritance:
- **Single Inheritance:** `Car` derived from `Vehicle` (`start()`, `drive()`).
- **Multilevel Inheritance:** `SportsCar` derived from `Car`, which derives from `Vehicle` (`turbo()`).
- **Multiple Inheritance:** `SmartDevice` inheriting from both `Camera` (`takePhoto()`) and `MusicPlayer` (`playMusic()`).
- **Hierarchical Inheritance:** Multiple derived classes `Cat` and `Cow` inheriting from base class `Animal` (`category()`).
- **Hybrid Inheritance:** Diamond inheritance hierarchy (`Account` -> `Teacher` & `Researcher` -> `Professor`) resolved using virtual inheritance (`virtual public Account`) to prevent ambiguity and duplication.

**Concepts used:**

- Base and derived classes, access control (`public` inheritance).
- Multilevel derivation: Derived classes inheriting all ancestors' public methods.
- Multiple inheritance: Combining features of disparate base classes into a single device.
- Hierarchical inheritance: Code reuse across sibling classes sharing a common ancestor.
- Virtual base classes (`virtual public`): Prevents duplicated base subobjects and resolves the diamond problem in hybrid inheritance.

**Sample run:**

```
Single Inheritance
Vehicle starts
Car is moving

Multilevel Inheritance
Vehicle starts
Car is moving
Turbo mode activated

Multiple Inheritance
Photo captured
Music is playing

Hierarchical Inheritance
Animal category
Cat says meow
Animal category
Cow says moo

Hybrid Inheritance
Account information shown
```
---

## Assignment 7 – Polymorphism

**File:** `opp7.cpp`

**Problem statement:** Implement a C++ program demonstrating compile-time and runtime polymorphism:
- **Compile-Time Polymorphism:**
  - *Function Overloading:* Overloaded `add()` in a `Calculator` class handling 2 integers, 2 doubles, and 3 integers.
  - *Operator Overloading:* Overloaded `+` operator in a `Complex` class to add two complex numbers directly (`c1 + c2`).
- **Runtime Polymorphism:**
  - Base class `Shape` with `virtual double area() const`, `virtual void show() const`, and a `virtual` destructor.
  - Derived classes `Circle`, `Rectangle`, and `Triangle` overriding `area()` and `show()`.
  - Base class pointer array (`Shape* shapes[4]`) dynamically invoking the appropriate derived methods, followed by virtual destructor cleanup via `delete`.

**Concepts used:**

- Function overloading resolved statically at compile time based on parameter signatures.
- Operator overloading extending `+` operator syntax to user-defined class objects.
- Virtual functions and dynamic binding via virtual method tables (`vptr`/`vtbl`).
- Virtual destructor: Ensures derived class destructors run when deleting objects via base pointers.
- Polymorphic array processing: Unified manipulation of diverse derived objects through base class pointers.

**Sample run:**

```
===== Compile-time Polymorphism =====

-- Function Overloading --
add(10, 20) = 30
add(2.5, 3.5) = 6
add(1, 2, 3) = 6

-- Operator Overloading --
c1 = 3 + 4i
c2 = 1 + 2i
c1 + c2 = 4 + 6i

===== Runtime Polymorphism =====
Generic Shape, Area = 0
Circle (r = 5), Area = 78.5397
Rectangle (4 x 6), Area = 24
Triangle (b = 3, h = 8), Area = 12
```
---

## Assignment 8 – Exception Handling

**File:** `opp8.cpp`

**Problem statement:** Implement a comprehensive C++ program demonstrating diverse exception handling techniques:
1. `try`, `throw`, and `catch` with primitive types (`int` age check for eligibility).
2. Throwing and catching `std::string` for division-by-zero detection.
3. Custom user-defined exception class (`InvalidMarksException`) validating student marks (0–100).
4. Standard library exceptions (`std::out_of_range`) from `<stdexcept>` for array bound checking.
5. Re-throwing an exception using `throw;` to pass an exception from an inner to an outer handler.
6. Multiple catch blocks with catch-all fallback (`catch (...)`).

**Concepts used:**

- Fundamental exception control flow: `try`, `throw`, and `catch`.
- Primitive exception throwing and type-matching.
- User-defined exception classes with custom diagnostic member functions (`show()`).
- Standard exceptions (`std::out_of_range`, `std::runtime_error`) and polymorphic catching with `const exception&`.
- Re-throwing exceptions (`throw;`) for multi-level diagnostics.
- Default catch-all handler (`catch (...)`) ensuring graceful fallback.

**Sample run:**

```
===== 1. try, throw and catch (int) =====
Access granted. Age is 20
Access denied. Age is 15 (must be 18 or above)

===== 2. Throwing a string =====
10 / 2 = 5
Exception caught: Division by zero is not allowed

===== 3. Custom exception class =====
Marks 85 are valid
Invalid marks entered: 120 (must be between 0 and 100)

===== 4. Standard exception (out_of_range) =====
arr[1] = 20
Exception caught: Index 5 is out of range

===== 5. Re-throwing an exception =====
Inner catch: Error occurred in inner function
Outer catch: Error occurred in inner function

===== 6. Multiple catch blocks and catch-all =====
Unknown (default) exception caught

Program ended normally.
```
---

## Assignment 9 – std::move() and Move Semantics

**File:** `opp9.cpp`

**Problem statement:** Implement a program demonstrating move semantics and `std::move()` in modern C++:
1. Moving `std::string` resources to eliminate deep string copying.
2. Moving `std::vector` to transfer heap-allocated dynamic array ownership in $O(1)$ time.
3. Designing a custom `Buffer` class featuring deep-copy constructor vs noexcept move constructor, comparing memory allocations and post-move object states.

**Concepts used:**

- Lvalues vs Rvalues and Rvalue References (`Type&&`).
- Resource acquisition and transfer via `std::move` (converting lvalues to rvalue references).
- Move constructors marked with `noexcept` to ensure exception-safe move semantics.
- Stealing resource pointers (`other.data = nullptr; other.size = 0;`) to avoid expensive heap allocations.
- State of moved-from objects.

**Sample run:**

```
===== 1. std::move with string =====

Before moving:
str1 = Hello, C++ Programming

After moving:
str1 = 
str2 = Hello, C++ Programming

===== 2. std::move with vector =====
Before moving: v1.size() = 5
After moving: v1.size() = 0, v2.size() = 5

===== 3. Copy constructor vs Move constructor =====
Constructor: allocated 5 ints
Copy constructor: copied 5 ints
Move constructor: moved 5 ints (no copy)

Buffer sizes after operations:
b1 size = 0
b2 size = 5
b3 size = 5

Program ended successfully.
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
| 6 | Single inheritance | Car inherits from Vehicle | Pass (start() and drive() called) |
| 6 | Multilevel inheritance | SportsCar inherits from Car and Vehicle | Pass (start(), drive(), turbo() called) |
| 6 | Multiple inheritance | SmartDevice inherits Camera & MusicPlayer | Pass (takePhoto() and playMusic() called) |
| 6 | Hierarchical inheritance | Cat & Cow inherit from Animal | Pass (Shared category() with specialized sounds) |
| 6 | Hybrid inheritance | Professor inherits Account via Teacher & Researcher | Pass (Resolved without ambiguity using virtual) |
| 7 | Function overloading | Calculator add() for int, double, and 3 params | Pass (Computed 30, 6, 6) |
| 7 | Operator overloading | Complex operator+ (c1 + c2) | Pass (Result: 4 + 6i) |
| 7 | Runtime polymorphism with Circle | Shape* -> Circle(5) | Pass (Area: 78.5397) |
| 7 | Runtime polymorphism with Rectangle | Shape* -> Rectangle(4, 6) | Pass (Area: 24) |
| 7 | Runtime polymorphism with Triangle | Shape* -> Triangle(3, 8) | Pass (Area: 12) |
| 8 | Integer exception handling | checkAge(20) vs checkAge(15) | Pass (Access granted for 20, denied for 15) |
| 8 | String exception on division by zero | divide(10, 0) | Pass (Caught: Division by zero is not allowed) |
| 8 | Custom exception class | validateMarks(120) | Pass (InvalidMarksException caught and displayed) |
| 8 | Standard exception (out_of_range) | getElement(arr, 3, 5) | Pass (Index 5 is out of range caught) |
| 8 | Re-throwing exceptions | innerFunction() rethrows | Pass (Caught at inner and outer level) |
| 8 | Catch-all handler | throw 3.14 (double) | Pass (Unknown/default exception caught) |
| 9 | std::move with std::string | Move str1 to str2 | Pass (str2 receives string, str1 emptied) |
| 9 | std::move with std::vector | Move v1 to v2 | Pass (v2 size 5, v1 size 0) |
| 9 | Copy constructor (deep copy) | Buffer b2 = b1 | Pass (Copied 5 ints, independent buffer allocated) |
| 9 | Move constructor (ownership transfer) | Buffer b3 = std::move(b1) | Pass (Moved 5 ints without allocation, b1 size 0) |


## Notes

- Names with spaces are read using `getline(cin, name)`, so the full name can be entered.
- All programs were compiled with `g++ -Wall -Wextra` without warnings.
