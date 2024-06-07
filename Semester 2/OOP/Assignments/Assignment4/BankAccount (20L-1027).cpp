#include "bankAccount.h"
#include<iostream>
using namespace std;
BankAccount::BankAccount(string name, int ID, double balance) : name(name), ID(ID), balance(balance)
{
	cout << "Overload Constructor Called." << endl;
	tran_capacity = 10;
	total_trans = 0;
	transactions = new double[tran_capacity] {};
}
void BankAccount::addtoTran(double amount)
{
	if (tran_capacity == total_trans)
	{
		growTranArray();
	}
	transactions[total_trans] = amount;
	total_trans++;
}
void BankAccount::growTranArray()
{
	int size = tran_capacity;
	double* temp = transactions;
	tran_capacity *= 2;
	transactions = new double[tran_capacity] {};
	for (int i = 0;i <= size;i++)
	{
		transactions[i] = temp[i];
	}
	delete[] temp;
	temp = nullptr;
}
void BankAccount::print() const
{
	cout << "Name : " << name << endl;
	cout << "Nick Name : " << nickName << endl;
	cout << "ID : " << ID << endl;
	cout << "Balance : " << balance << endl;
}
void BankAccount::withDraw(double amount)
{
	if (balance >= amount)
	{
		balance -= amount;
		amount *= -1;
		addtoTran(amount);
	}
	else
	{
		cout << "Insufficient Balance." << endl;
	}
}
void BankAccount::deposit(double amount)
{
	balance += amount;
	addtoTran(amount);
}
void BankAccount::setNickName(string n)
{
	nickName = n;
}
void BankAccount::printLastNTransactions(int n) const
{
	if (total_trans == 0)
	{
		cout << "No transations made yet." << endl;
	}
	else
	{
		cout << "Transactions : ";
		for (int i = total_trans-1;i >= total_trans - (n);i--)
		{
			if (transactions[i] != 0 && (!(i>total_trans) && !(i<0)))
			{
				cout << transactions[i] << " ";
			}
		}
		cout << endl;
	}
}
double BankAccount::getBalance()const
{
	return balance;
}
BankAccount::~BankAccount()
{
	cout << "Destructor Called." << endl;
	delete[] transactions;
}