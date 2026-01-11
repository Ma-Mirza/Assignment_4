#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class BankAccount {
private:
	string accountHolder;
	double balance;
public:
	BankAccount(string _accountHolder,double _balance):accountHolder(_accountHolder),balance(_balance) {
		cout << "Constructor called for " << accountHolder << endl;
		if (balance < 0)
			throw invalid_argument("Initial balance cannot be negative.");
		cout << "Account Created for: " << accountHolder << endl;
		cout << "Initial Balance: " << balance << endl;
	}
	void withDraw() {
		double amount;
		cout << "Enter Amount to Withdraw: ";
		cin >> amount;
		if (amount > balance)
			throw runtime_error("Withdrawl Amount is Greater than Your Balance ");
		balance = balance - amount;
		cout << "Amount: " << amount << " is Withdrawn Successfully " << endl;
		cout << "Current Balance: " << balance << endl;
	}
	~BankAccount(){
		cout << "Destructor Called for: " << accountHolder << endl;
	}
};
int main() {
	BankAccount* acc1=nullptr;
	BankAccount* acc2 = nullptr;	
		try {
			acc1 = new BankAccount("Muhammad Abdullah Mirza", 1000);
			try {
				acc1->withDraw();
			}
			catch (const runtime_error& obj) {
				cout << "Exception Hapened: " << obj.what() << endl;
			}
			delete acc1;
			acc1 = nullptr;
		}
		catch (const invalid_argument &obj) {
			cout << "Invalid Account Creation: " << obj.what()<< endl;
			if (acc1)
				delete acc1;
			
		}
		cout << "\n---------------------------------------------" << endl;
		try {
			acc2 = new BankAccount("Asif Mirza", -5000);
			delete acc2;
			acc2 = nullptr;
		}
		catch (const invalid_argument &obj) {
			cout << "Exception happened: " <<obj.what()<< endl;

		}
		
		cout << "\n---------------------------------------------" << endl;

}