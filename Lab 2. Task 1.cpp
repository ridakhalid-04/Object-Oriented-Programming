#include<iostream>
using namespace std;
class Account{
private:
	string accountNumber;
	double balance;
public:
	Account(string accNum, double bal){
		accountNumber = accNum;
		balance = bal;
	}
	Account operator+(Account &other){
		Account temp("0",0);
		temp.balance = this->balance + other.balance;
		temp.accountNumber = "Combined_" + this->accountNumber;
		return temp;
	}
	void show(){
		cout << "Account Number: " << accountNumber << endl;
		cout << "Balance: " << balance << endl;
	}
	
};
int main(){
	Account A1("1001", 5000);
	Account A2("1002", 3000);
	Account A3 = A1 + A2;
	cout << "Account 1:" << endl;
	A1.show();
	cout << "Account 2: " << endl;
	A2.show();
	cout << "Combined Account: " << endl;
	A3.show();
	return 0;
}
