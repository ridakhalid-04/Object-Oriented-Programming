// Lab Task: Static members and static functions - Ride-Sharing App
#include <iostream>
#include <iomanip>
using namespace std;

class Ride {
private:
    // ---- Part 1a: Instance (non-static) members: unique for every Ride object ----
    int    rideId;
    double fare;

    // ---- Part 1b: Static data members: shared by ALL rides ----
    static int    totalRides;      // total number of rides
    static double totalRevenue;    // total money from all rides
    static double taxRate;         // platform tax rate in percent

public:
    // ---- Part 3: Constructor updates the global data automatically ----
    Ride(double f) : fare(f) {
        totalRides++;              // one more ride in the system
        rideId = totalRides;       // unique ID: 1, 2, 3 ...
        totalRevenue += fare;      // add this fare to global revenue
    }

    // Instance function: tax on this specific ride using the global rate
    double getTax() const { return fare * taxRate / 100.0; }

    void display() const {
        cout << "Ride ID: " << rideId
             << " | Fare: $" << fixed << setprecision(2) << fare
             << " | Tax (" << taxRate << "%): $" << getTax() << endl;
    }

    // ---- Part 2: Static member functions ----
    // Admin view: total rides and total revenue (no object needed)
    static void showStatistics() {
        cout << "\n===== Company Statistics =====\n";
        cout << "Total Rides   : " << totalRides << endl;
        cout << "Total Revenue : $" << fixed << setprecision(2) << totalRevenue << endl;
        cout << "Tax Rate      : " << taxRate << "%" << endl;
        cout << "==============================\n";
    }

    // Admin change: update the global tax rate
    static void setTaxRate(double newRate) {
        if (newRate >= 0) taxRate = newRate;
    }
};

// Static data members must be defined (and initialized) outside the class
int    Ride::totalRides   = 0;
double Ride::totalRevenue = 0.0;
double Ride::taxRate      = 10.0;   // default 10%

int main() {
    // Static function can be called before any object exists
    cout << "Before any ride:";
    Ride::showStatistics();

    Ride r1(25.50);
    Ride r2(40.00);
    Ride r3(15.75);

    cout << "\n--- Individual Rides (tax rate 10%) ---\n";
    r1.display();
    r2.display();
    r3.display();
    Ride::showStatistics();

    // Admin changes the tax rate: applies to ALL rides
    cout << "\nAdmin changes tax rate to 12%...\n";
    Ride::setTaxRate(12);

    cout << "\n--- Individual Rides (tax rate 12%) ---\n";
    r1.display();
    r2.display();
    r3.display();

    Ride r4(60.25);   // new ride updates global data automatically
    cout << "\nNew ride booked:\n";
    r4.display();
    Ride::showStatistics();

    return 0;
}