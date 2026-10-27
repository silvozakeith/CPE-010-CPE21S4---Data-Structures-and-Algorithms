#include <iostream>
#include <cmath>
using namespace std;

// Function Prototype
double calculateDistance(double x1, double y1, double x2, double y2);

int main() {
    double x1, y1, x2, y2;

    cout << "Enter x1: ";
    cin >> x1;

    cout << "Enter y1: ";
    cin >> y1;

    cout << "Enter x2: ";
    cin >> x2;

    cout << "Enter y2: ";
    cin >> y2;

    cout << "Distance between points: "
         << calculateDistance(x1, y1, x2, y2) << endl;

    return 0;
}

// Function Definition
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}