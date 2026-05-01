#include<iostream>
using namespace std;
class Account{
private:
	string accountNumber;
	double balance;
public:
	void getData(){
		cout << "Enter account number: " << endl;
		cin >> accountNumber;
		cout << "Enter balamce: " << endl;
		cin >> balance;
	}
	void showData(){
		cout << "Account details: " << endl;
		cout << "Account number: " << accountNumber << endl;
		cout << "Balance: " << balance << endl; 
	}
};
int main()
{
	Account acc;
	acc.getData();
	acc.showData();
	return 0;
}
