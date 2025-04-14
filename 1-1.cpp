#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNumber, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }

    void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        checkBalance();
    }
};


int main() {
 
    BankAccount myAccount("khush", 1001, 500.0);

    
    myAccount.displayAccountInfo();
    cout << endl;

    myAccount.deposit(200.0);
    myAccount.withdraw(150.0);
    myAccount.withdraw(600.0); 
    myAccount.checkBalance();

    return 0;
}
