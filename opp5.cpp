#include <iostream>
#include <string>
using namespace std;

// Real-life example: Bank accounts audited by a bank Auditor.
// Concepts: class, objects, this pointer, inline function,
//           static member function, friend class.

class BankAccount
{
private:
    string holderName;
    int accountNumber;
    double balance;
    static int totalAccounts;      // shared by ALL objects (one copy only)

    friend class Auditor;          // Auditor can access private members

public:
    // Constructor: 'this' pointer separates member names from parameter names
    BankAccount(string holderName, int accountNumber, double balance)
    {
        this->holderName = holderName;
        this->accountNumber = accountNumber;
        this->balance = balance;
        totalAccounts++;           // a new account is opened
    }

    // Destructor: account closed when object is destroyed
    ~BankAccount()
    {
        totalAccounts--;
    }

    // 'this' pointer: returning *this allows chaining: acc.deposit(100).withdraw(50)
    BankAccount& deposit(double amount)
    {
        this->balance += amount;
        return *this;
    }

    BankAccount& withdraw(double amount)
    {
        if (amount <= this->balance)
            this->balance -= amount;
        else
            cout << "Insufficient balance for " << holderName << "!" << endl;
        return *this;
    }

    // Inline function (defined inside the class -> implicitly inline)
    double getBalance() const { return balance; }

    // Inline function declared here, defined outside with 'inline' keyword
    inline void display() const;

    // Static member function: works on class data, no object needed
    static int getTotalAccounts()
    {
        return totalAccounts;
    }
};

// Static data member must be defined outside the class
int BankAccount::totalAccounts = 0;

inline void BankAccount::display() const
{
    cout << "Account No: " << accountNumber
         << " | Holder: " << holderName
         << " | Balance: Rs. " << balance << endl;
}

// Friend class: can read/modify private data of BankAccount
class Auditor
{
public:
    // Reads private data directly
    void audit(const BankAccount& acc)
    {
        cout << "[Audit] " << acc.holderName
             << " (A/C " << acc.accountNumber << ") has Rs. "
             << acc.balance << endl;
    }

    // Modifies private data directly
    void addInterest(BankAccount& acc, double ratePercent)
    {
        acc.balance += acc.balance * ratePercent / 100;
    }
};

int main()
{
    cout << "=== Bank Account Management ===" << endl;
    cout << "Accounts at start: " << BankAccount::getTotalAccounts() << endl;

    // Objects
    BankAccount acc1("Sushrut", 1001, 5000);
    BankAccount acc2("Rahul", 1002, 8000);
    cout << "Accounts after opening: " << BankAccount::getTotalAccounts() << endl;

    cout << "\n--- Initial details ---" << endl;
    acc1.display();
    acc2.display();

    // Function chaining using 'this' pointer
    cout << "\n--- Transactions (chained calls) ---" << endl;
    acc1.deposit(2000).withdraw(500).deposit(300);
    acc2.withdraw(10000);              // fails: insufficient balance
    acc1.display();
    acc2.display();

    // Friend class in action
    cout << "\n--- Auditor (friend class) ---" << endl;
    Auditor auditor;
    auditor.audit(acc1);
    auditor.audit(acc2);
    auditor.addInterest(acc1, 4);      // 4% interest
    cout << "After 4% interest, balance of " << "Sushrut"
         << ": Rs. " << acc1.getBalance() << endl;

    cout << "\nTotal accounts: " << BankAccount::getTotalAccounts() << endl;
    return 0;
}
