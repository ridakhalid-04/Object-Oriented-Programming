#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

public:
    void input() {
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void generateAccountNumber() {
        accountNumber = rand() % 10000;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    srand(time(0));

    Account a1;

    a1.input();
    a1.generateAccountNumber();
    a1.display();

    return 0;
}