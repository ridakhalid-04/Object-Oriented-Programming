#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

public:
    void input() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Balance: ";
        cin >> balance;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Account a1;

    a1.input();
    a1.display();

    return 0;
}