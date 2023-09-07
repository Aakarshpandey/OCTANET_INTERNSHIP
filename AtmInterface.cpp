#include <iostream>

// BankAccount class to represent the user's account
class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }
};

// ATM class to represent the ATM machine
class ATM {
private:
    BankAccount* userAccount;

public:
    ATM(BankAccount* account) {
        userAccount = account;
    }

    void displayMenu() {
        std::cout << "\nATM Menu:" << std::endl;
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Exit" << std::endl;
    }

    void withdraw(double amount) {
        if (userAccount->withdraw(amount)) {
            std::cout << "Withdrawn: $" << amount << std::endl;
        } else {
            std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
        }
    }

    void deposit(double amount) {
        userAccount->deposit(amount);
        std::cout << "Deposited: $" << amount << std::endl;
    }

    void checkBalance() {
        double balance = userAccount->getBalance();
        std::cout << "Current Balance: $" << balance << std::endl;
    }
};

int main() {
    std::cout << "Enter initial balance: $";
    double initialBalance;
    std::cin >> initialBalance;

    BankAccount* userAccount = new BankAccount(initialBalance);
    ATM* atm = new ATM(userAccount);

    int choice;
    do {
        atm->displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                atm->checkBalance();
                break;
            case 2: {
                double depositAmount;
                std::cout << "Enter deposit amount: $";
                std::cin >> depositAmount;
                atm->deposit(depositAmount);
                break;
            }
            case 3: {
                double withdrawalAmount;
                std::cout << "Enter withdrawal amount: $";
                std::cin >> withdrawalAmount;
                atm->withdraw(withdrawalAmount);
                break;
            }
            case 4:
                std::cout << "Exiting ATM. Thank you!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    delete atm;
    delete userAccount;

    return 0;
}
