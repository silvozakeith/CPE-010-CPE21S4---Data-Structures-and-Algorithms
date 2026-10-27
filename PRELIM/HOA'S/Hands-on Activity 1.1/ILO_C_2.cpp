#include <iostream>
using namespace std;

// Function Prototype
double kelvinToFahrenheit(double kelvin);

int main() {
    double kelvin;

    cout << "Enter temperature in Kelvin: ";
    cin >> kelvin;

    cout << "Temperature in Fahrenheit: "
         << kelvinToFahrenheit(kelvin) << endl;

    return 0;
}

// Function Definition
double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}