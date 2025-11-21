#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    // Method to write data to file
    void saveToFile() {
        ofstream out("items.txt");
        if (out.is_open()) {
            out << name << "," << quantity << endl;
            out.close();
            cout << "Item saved to file." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    // Method to read data from file
    void loadFromFile() {
        ifstream in("items.txt");
        if (in.is_open()) {
            string line;
            cout << "--- Reading from file ---" << endl;
            while (getline(in, line)) {
                cout << "File content: " << line << endl;
            }
            in.close();
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    // Create an instance of Item
    Item tool;
    
    // Assign values
    tool.name = "Screwdriver";
    tool.quantity = 10;

    // Call methods
    tool.saveToFile();
    tool.loadFromFile();

    return 0;
}