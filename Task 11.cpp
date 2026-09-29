// Lab Task: Shallow Copy vs Deep Copy - Employee record system
#include <iostream>
using namespace std;

// ---------- Shallow copy: compiler-generated copy constructor ----------
class ShallowEmployee {
private:
    int  id;
    int* salary;          // dynamically allocated
public:
    ShallowEmployee(int i, int s) : id(i), salary(new int(s)) {}
    // No copy constructor written -> default copies the POINTER only
    void setSalary(int s) { *salary = s; }
    void display(const char* label) const {
        cout << label << " -> ID: " << id << ", Salary: " << *salary
             << " (address: " << salary << ")" << endl;
    }
    // Called manually ONCE. A normal destructor would delete the same memory
    // twice (both objects point to it) and crash the program.
    void release() { delete salary; }
};

// ---------- Deep copy: user-defined copy constructor ----------
class Employee {
private:
    int  id;
    int* salary;
public:
    Employee(int i, int s) : id(i), salary(new int(s)) {}

    // Copy constructor: allocates NEW memory and copies the VALUE
    Employee(const Employee& other) : id(other.id), salary(new int(*other.salary)) {}

    void setSalary(int s) { *salary = s; }
    void display(const char* label) const {
        cout << label << " -> ID: " << id << ", Salary: " << *salary
             << " (address: " << salary << ")" << endl;
    }
    ~Employee() { delete salary; }
};

int main() {
    cout << "===== SHALLOW COPY =====\n";
    ShallowEmployee s1(101, 50000);
    ShallowEmployee s2 = s1;          // pointer copied, memory shared

    cout << "Before change:\n";
    s1.display("Original");
    s2.display("Copy    ");

    s2.setSalary(75000);              // change only the copy
    cout << "\nAfter changing copy's salary to 75000:\n";
    s1.display("Original");
    s2.display("Copy    ");
    cout << "Original was ALSO changed: both share the same memory.\n";
    s1.release();                     // free shared memory once

    cout << "\n===== DEEP COPY =====\n";
    Employee d1(102, 50000);
    Employee d2 = d1;                 // copy constructor: new memory

    cout << "Before change:\n";
    d1.display("Original");
    d2.display("Copy    ");

    d2.setSalary(75000);              // change only the copy
    cout << "\nAfter changing copy's salary to 75000:\n";
    d1.display("Original");
    d2.display("Copy    ");
    cout << "Original is unchanged: each object has its own memory.\n";

    return 0;
}