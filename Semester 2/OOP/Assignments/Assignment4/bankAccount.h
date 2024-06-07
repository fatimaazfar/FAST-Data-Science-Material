#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
	const string name;
	string nickName;
	const int ID;
	double balance;
	double* transactions;
	int tran_capacity;
	int total_trans;

	/*Utiltity function to add the amount to the transcation array
	will call growTranArray function if its full*/
	void addtoTran(double amount);
	/*Will double the capacity of transaction array*/
	void growTranArray();

public:
	/*overloaded constructors*/
	BankAccount(string name, int ID, double balance = 0);
	void print() const;
	/*withdraw money if that balance is available
	-ve of amount is added to transactions array
	balance also decreases by same amount*/
	void withDraw(double amount);
	/*deposit money
	 amount is added to transactions array
	 balance increase by the same amount.*/
	void deposit(double amount);
	/*will update the nickname*/
	void setNickName(string n);
	/*Will print the last n transactions, default value of n=10*/
	void printLastNTransactions(int n = 10) const;
	double getBalance()const;
	~BankAccount();


};