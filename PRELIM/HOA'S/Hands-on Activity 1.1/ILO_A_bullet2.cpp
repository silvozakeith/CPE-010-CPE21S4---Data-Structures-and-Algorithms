#include <iostream>
using namespace std;

// Function Prototype
bool isAGreaterThanB(int A, int B);

int main() {
    int A, B;

    cout << "Enter value of A: ";
    cin >> A;

    cout << "Enter value of B: ";
    cin >> B;

    if (isAGreaterThanB(A, B)) {
        cout << "A is greater than B." << endl;
    } 
    else {
        cout << "A is not greater than B." << endl;
    }

    return 0;
}

// Function Definition
bool isAGreaterThanB(int A, int B) {
    return A > B;
}