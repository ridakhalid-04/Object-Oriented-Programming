// Q2: Neo-Tokyo Centralized Fleet Controller
#include <iostream>
using namespace std;

// ---------- Secure Base Class ----------
class Vehicle {
private:
    int fuel;                       // private: children cannot touch it directly

public:
    Vehicle(int f) : fuel(f) {}

    // Secure gates (public methods)
    int getFuel() const { return fuel; }

    void useFuel(int amount) {      // only way to reduce fuel
        if (amount < 0) return;
        fuel -= amount;
        if (fuel < 0) fuel = 0;     // fuel never goes negative
    }

    void refuel(int amount) {
        if (amount > 0) fuel += amount;
    }

    virtual void move() = 0;        // pure virtual -> Vehicle is abstract
    virtual ~Vehicle() {}           // virtual destructor
};

// ---------- Drone ----------
class Drone : public Vehicle {
public:
    Drone(int f) : Vehicle(f) {}

    void move() override {
        if (getFuel() >= 10) {      // safety buffer of at least 10
            useFuel(5);
            cout << "Drone flying...   Fuel left: " << getFuel() << endl;
        } else {
            cout << "Drone cannot take off! Fuel (" << getFuel()
                 << ") is below the safety buffer of 10." << endl;
        }
    }
};

// ---------- Train ----------
class Train : public Vehicle {
public:
    Train(int f) : Vehicle(f) {}

    void move() override {
        if (getFuel() > 0) {        // any fuel left is enough
            useFuel(10);
            cout << "Train moving...   Fuel left: " << getFuel() << endl;
        } else {
            cout << "Train cannot move! Tank is empty." << endl;
        }
    }
};

// ---------- main: runtime polymorphism ----------
int main() {
    Vehicle* fleet[2];
    fleet[0] = new Drone(18);       // base-class pointers ("universal remote")
    fleet[1] = new Train(25);

    for (int round = 1; round <= 4; round++) {
        cout << "\n--- Round " << round << " ---\n";
        for (int i = 0; i < 2; i++)
            fleet[i]->move();       // dynamic binding: derived move() runs
    }

    for (int i = 0; i < 2; i++)
        delete fleet[i];            // virtual destructor -> no leaks

    return 0;
}