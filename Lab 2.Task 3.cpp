#include <iostream>
#include<cstdlib>
using namespace std;

class Account
{
private:
    int accountNumber;

public:
    void generateAccountNumber()
    {
        accountNumber = rand() % 90000 + 10000; 
    }
    void display()
    {
        cout << "Generated Account Number: " << accountNumber << endl;
    }
};

int main()
{
    Account A1;
    A1.generateAccountNumber();
    A1.display();

    return 0;
}
