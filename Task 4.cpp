// Q1: Shape Area - Runtime Polymorphism with virtual functions
#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159265359;

class Shape {
public:
    virtual double area() const = 0;   // overridden by derived classes
    virtual ~Shape() {}                // virtual destructor
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return PI * radius * radius; }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Rectangle(10, 5);
    shapes[1] = new Circle(7);

    cout << fixed << setprecision(2);
    cout << "Area of Rectangle (10 x 5): " << shapes[0]->area() << endl;
    cout << "Area of Circle (radius 7) : " << shapes[1]->area() << endl;

    for (int i = 0; i < 2; i++)
        delete shapes[i];   // virtual destructor -> full cleanup

    return 0;
}