#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNumber, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds. Current balance: $" << balance << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        }
    }

    void checkBalance() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};


int main() {
    
    BankAccount myAccount("khush", 1001, 500.00);

    myAccount.checkBalance();
    myAccount.deposit(250.00);
    myAccount.withdraw(100.00);
    myAccount.withdraw(1000.00); 
    myAccount.checkBalance();

    return 0;
}