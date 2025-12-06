#include <iostream>
using namespace std;

int main() {
    int choice;

    // Display the menu options
    cout << "1. Add Item\n2. View Items\n3. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;

    // Handle user input using if/else if statements
    if (choice == 1) {
        cout << "Item added!\n";
    }
    else if (choice == 2) {
        cout << "Displaying items...\n";
    }
    else if (choice == 3) {
        cout << "Exiting...\n";
    }
    else {
        cout << "Invalid option.\n";
    }

    return 0;
}