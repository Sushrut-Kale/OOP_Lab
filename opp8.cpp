#include <iostream>
#include <stdexcept>
using namespace std;

// Real-life example: Banking transaction system with balance safeguards.
// Concepts: Exception handling (try, throw, catch), standard exceptions
//           (std::invalid_argument, std::runtime_error), and state consistency.

class BankAccount {
private:
    double balance;

public:
    // Constructor
    BankAccount(double b) {
        balance = b;
    }

    // Function to withdraw money with exception handling
    void withdraw(double amount) {
        try {
            // Throw invalid_argument exception for zero or negative amounts
            if (amount <= 0) {
                throw invalid_argument(
                    "Invalid amount! Enter a positive amount."
                );
            }

            // Throw runtime_error exception when balance is insufficient
            if (amount > balance) {
                throw runtime_error(
                    "Insufficient balance! Withdrawal denied."
                );
            }

            balance = balance - amount;

            cout << "Withdrawal Successful!" << endl;
            cout << "Withdrawn Amount: Rs. " << amount << endl;
            cout << "Remaining Balance: Rs. " << balance << endl;
        }
        catch (const invalid_argument &e) {
            cout << "Exception: " << e.what() << endl;
        }
        catch (const runtime_error &e) {
            cout << "Exception: " << e.what() << endl;
        }
    }

    // Display balance
    void displayBalance() const {
        cout << "Current Balance: Rs. " << balance << endl;
    }

    // Destructor
    ~BankAccount() {
        cout << "Bank Account Object Destroyed." << endl;
    }
};

int main() {
    double amount;

    // Create bank account with initial deposit
    BankAccount account(5000);

    cout << "===== BANKING SYSTEM =====" << endl;
    account.displayBalance();

    cout << "\nEnter amount to withdraw: Rs. ";
    cin >> amount;

    // Withdraw money (validated using exception handling)
    account.withdraw(amount);

    cout << "\nFinal Account Details:" << endl;
    account.displayBalance();

    return 0;
}
