#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;

public:
    // Constructor: Initializes the object
    Product(int i, string n, float p) {
        id = i;
        name = n;
        price = p;
        cout << "Constructor called for: " << name << endl;
    }

    // Destructor: Cleans up the object
    ~Product() {
        cout << "Destructor called for: " << name << endl;
    }

    // Method to display details
    void printDetails() {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

int main() {
    // Create a Product object (Constructor is called here)
    Product p(101, "Gaming Laptop", 1299.99);

    // Use the object
    p.printDetails();

    // The Destructor will be called automatically when 'p' goes out of scope (at the return 0)
    return 0;
}