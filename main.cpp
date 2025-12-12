#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // For formatting currency

using namespace std;

class BankAccount {
private:
    double balance;

    // Helper method to save transaction to file
    void saveTransaction(string type, double amount) {
        // Open file in append mode (ios::app) so we don't overwrite previous history
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << fixed << setprecision(2) << amount << endl;
            file.close();
        } else {
            cout << "Error: Unable to save transaction to file." << endl;
        }
    }

public:
    // Constructor
    BankAccount() {
        balance = 0.0;
    }

    // Method to deposit funds
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
            cout << "Current Balance: $" << balance << endl;
            saveTransaction("Deposit", amount);
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
        cout << "-----------------------------------" << endl;
    }

    // Method to make a purchase
    void makePurchase(string item, double cost) {
        if (cost > balance) {
            cout << "Transaction Declined: Insufficient funds for " << item << endl;
            cout << "Cost: $" << cost << " | Available: $" << balance << endl;
        } else {
            balance -= cost;
            cout << "Purchased: " << item << " for $" << fixed << setprecision(2) << cost << endl;
            saveTransaction("Purchase - " + item, cost);
        }
        cout << "-----------------------------------" << endl;
    }

    // Method to display current balance
    void displayBalance() {
        cout << "=== Final Account Summary ===" << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

int main() {
    // 1. Create BankAccount object
    BankAccount myAccount;

    cout << "--- Banking Simulation Started ---\n" << endl;

    // Clear previous transaction logs for a clean run (optional)
    ofstream clearFile("transactions.txt");
    clearFile.close();

    // 2. Add an initial deposit
    myAccount.deposit(500.00);

    // 3. Make at least two purchases
    myAccount.makePurchase("Textbook", 125.50);
    myAccount.makePurchase("Coffee", 5.75);
    myAccount.makePurchase("Laptop", 1200.00); // This should fail (insufficient funds)

    // 4. Print final balance
    myAccount.displayBalance();

    cout << "\nTransaction history saved to 'transactions.txt'." << endl;

    return 0;
}