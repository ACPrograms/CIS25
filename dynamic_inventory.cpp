#include <iostream>
#include <string>
using namespace std;

// 1. Define a struct named Item
struct Item {
    string name;
    int id;
};

// Binary Search Function
// Returns the index of the item if found, or -1 if not found
int binarySearch(Item* arr, int size, int targetId) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate middle index

        // Check if the target is present at mid
        if (arr[mid].id == targetId) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid].id < targetId) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // Target was not found
    return -1;
}

int main() {
    int size = 100;

    // 2. Use new to dynamically allocate an array of items
    Item* inventory = new Item[size];

    // 3. Populate the array with sorted sample data (min 100 records)
    // We are populating IDs 1000 through 1099 so they are sorted for the binary search.
    for (int i = 0; i < size; i++) {
        inventory[i].id = 1000 + i; 
        inventory[i].name = "Widget_Model_" + to_string(i);
    }

    cout << "Inventory System Initialized with " << size << " items." << endl;
    
    // 4 & 5. Ask user for ID and search
    int searchID;
    cout