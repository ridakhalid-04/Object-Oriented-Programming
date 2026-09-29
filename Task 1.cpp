#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

public:
    
    Account(int acc, double bal) {
        accountNumber = acc;
        balance = bal;
    }

    
    Account operator+(Account obj) {
        Account temp(0, 0);
        temp.balance = balance + obj.balance;
        temp.accountNumber = 888; 
        return temp;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Account a1(101, 5000);
    Account a2(102, 3000);

    Account a3 = a1 + a2;

    cout << "Combined Account:\n";
    a3.display();

    return 0;
}