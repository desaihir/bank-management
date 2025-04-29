#include <stdio.h>
#include <iostream>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int balance;
    // string accountNumber;
    char aT;
    string accountType;
    string address;
public:
    void openAccount();
    void depositMoney();
    void withdrawMoney();
    void checkBalance();
};

void BankAccount::openAccount() {
    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, accountHolderName);
    balance = 0; // Initial balance is set to 0
    cout << "Enter your address: ";
    cin.ignore();
    getline(cin, address); 
    cout<<"Enter the type of account Savings (s) or Current(c): ";
    cin >> aT;
    if(aT == 's' || aT == 'S') {
        accountType = "Savings";
    } else if(aT == 'c' || aT == 'C') {
        accountType = "Current";
    } else {
        cout << "Invalid account type. Please enter 's' for Savings or 'c' for Current." << endl;
        return;
    }
    cout << "Account type: " << accountType << endl;
    cout<<"Enter amount to deposit: ";
    cin >> balance;
    cout << "Account opened successfully for " << accountHolderName << endl;
}

void BankAccount::depositMoney() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
        cout << "New balance: " << balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

void BankAccount::withdrawMoney() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
        cout << "New balance: " << balance << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds." << endl;
    } else {
        cout << "Invalid withdrawal amount." << endl;
    }
}

void BankAccount::checkBalance() {
    cout << "Account holder: " << accountHolderName << endl;
    cout << "Account type: " << accountType << endl;
    cout << "Address: " << address << endl;
    cout << "Current balance: " << balance << endl;
}



int main() {
    BankAccount account;

    do{
    int choice;
    cout << "Welcome to the Bank Management System" << endl;
    cout<<"1. Open Account"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. Check Balance"<<endl;
    cout<<"5. Exit"<<endl;
    
    cout<<"Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: {
            // BankAccount account;
            cout << "Opening a new account..." << endl;
            account.openAccount();
            break;
        }
        case 2: {
            cout << "Depositing money..." << endl;
            // BankAccount account;
            account.depositMoney();
            break;
        }
        case 3: {
            cout << "Withdrawing money..." << endl;
            // BankAccount account;
            account.withdrawMoney();
            break;
        }
        case 4: {
            cout << "Checking balance..." << endl;
            // BankAccount account;
            account.checkBalance();
            break;
        }
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    } while (true);
    return 0;
}