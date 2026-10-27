#include <iostream>
using namespace std;

// Function Prototype
void displaySum(int num1, int num2);

int main() {
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    displaySum(a, b);

    return 0;
}

// Function Definition
void displaySum(int num1, int num2) {
    cout << "Sum = " << num1 + num2 << endl;
}