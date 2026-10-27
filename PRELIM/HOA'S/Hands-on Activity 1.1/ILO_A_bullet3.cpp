#include <iostream>
using namespace std;

// Function Prototype
bool logicalOperations(bool x, bool y);

int main() {
    bool a, b;

    cout << "Enter first Boolean value (0 or 1): ";
    cin >> a;

    cout << "Enter second Boolean value (0 or 1): ";
    cin >> b;

    if (logicalOperations(a, b)) {
        cout << "Operation completed successfully." << endl;
    }

    return 0;
}

// Function Definition
bool logicalOperations(bool x, bool y) {
    cout << "\nLogical Operations:" << endl;

    cout << "AND (x && y): " << (x && y) << endl;
    cout << "OR (x || y): " << (x || y) << endl;
    cout << "NOT x (!x): " << (!x) << endl;
    cout << "NOT y (!y): " << (!y) << endl;

    return true;
}