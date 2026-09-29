// Lab Task: Exception Handling - Calculator (addition)
#include <iostream>
using namespace std;

double add(double a, double b) {
    if (a < 0 || b < 0)
        throw "Error: Negative numbers are not allowed!";
    return a + b;
}

int main() {
    double num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    try {
        double result = add(num1, num2);
        cout << "Sum = " << result << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    cout << "Program ended normally." << endl;
    return 0;
}