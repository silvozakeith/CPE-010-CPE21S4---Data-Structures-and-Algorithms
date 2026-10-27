#include <iostream>
using namespace std;

// Class Declaration Section
class Triangle {
private:
    double totalAngle;
    double angleA, angleB, angleC;

public:
    // Constructor
    Triangle(double A, double B, double C);

    // Method to change angles
    void setAngles(double A, double B, double C);

    // Method to validate triangle
    const bool validateTriangle();
};


// Method Definition Section

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}


// Main Function / Driver Code

int main() {

    Triangle set1(40, 30, 110);

    if (set1.validateTriangle()) {
        cout << "The shape is a valid triangle." << endl;
    }
    else {
        cout << "The shape is NOT a valid triangle." << endl;
    }

    return 0;
}