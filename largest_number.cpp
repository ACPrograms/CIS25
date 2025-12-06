#include <iostream>
using namespace std;

int main() {
    // FIX: Variables must be separated by commas and end with a semicolon.
    // Original Error: float n1 n2 n3,
    float n1, n2, n3;

    cout << "Enter three numbers: ";

    // FIX: Used proper input extraction operators (>>)
    // Original Error: cin >> n1 > n1 > n3;
    cin >> n1 >> n2 >> n3;

    // FIX: Implemented NESTED if statements as required by the instructions.
    // This replaces the broken logic from the slide (if(n1 = n2 && ...))

    if (n1 >= n2) {
        // If n1 is greater than or equal to n2, now compare n1 vs n3
        if (n1 >= n3) {
            cout << "Largest number: " << n1 << endl;
        } else {
            // If n1 is not >= n3, then n3 must be the largest
            cout << "Largest number: " << n3 << endl;
        }
    } else {
        // If n1 is less than n2, now compare n2 vs n3
        if (n2 >= n3) {
            cout << "Largest number: " << n2 << endl;
        } else {
            // If n2 is not >= n3, then n3 must be the largest
            cout << "Largest number: " << n3 << endl;
        }
    }

    return 0;
}