#include <iostream>
#include <string>
using namespace std;

// Base Class
class Account {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    Account(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    // Deposit Function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited Successfully!\n";
        } else {
            cout << "Invalid Deposit Amount!\n";
        }
    }

    // Withdraw Function
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance or Invalid Amount!\n";
        }
    }

    // Display Function
    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived Class (Inheritance)
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // Constructor
    SavingsAccount(int accNo, string name, double bal, double rate)
        : Account(accNo, name, bal) {
        interestRate = rate;
    }

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest Added Successfully!\n";
    }
};

int main() {
    int accNo;
    string name;
    double initialBalance;
    double rate;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cin.ignore();
    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    cout << "Enter Interest Rate (%): ";
    cin >> rate;

    SavingsAccount acc(accNo, name, initialBalance, rate);

    int choice;
    double amount;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Add Interest\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            acc.deposit(amount);
            break;

        case 2:
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
            break;

        case 3:
            acc.addInterest();
            break;

        case 4:
            acc.display();
            break;

        case 5:
            cout << "Thank You for Using Bank System!\n";
            break;

        default:
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}
