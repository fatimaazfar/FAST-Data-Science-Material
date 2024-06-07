#include <iostream>
#include "bankAccount.h"
using namespace std;
int main()
{

	BankAccount B1("Ali", 15);
	B1.print();
	/*
	Name: Ali
	NickName:
	ID: 15
	Balance: 0
	*/

	B1.setNickName("AN");
	B1.print();
	/*Name: Ali
	NickName: AN
	ID: 15
	Balance: 0
	*/

	B1.printLastNTransactions();
	//No transaction made yet

	B1.withDraw(100);
	//Balance not enough to make this transaction

	B1.deposit(50000);

	B1.printLastNTransactions();
	//Transactions: 50000

	B1.deposit(40000);
	B1.deposit(30000);
	B1.deposit(20000);
	B1.deposit(10000);
	cout << "Balance: " << B1.getBalance() << endl;
	//Balance: 150000


	B1.printLastNTransactions(7);
	//Transactions: 10000, 20000, 30000, 40000, 50000

	B1.printLastNTransactions(3);
	//Transactions: 10000, 20000, 30000


	B1.withDraw(100);
	B1.withDraw(200);
	B1.withDraw(300);
	B1.withDraw(400);
	B1.withDraw(500);
	B1.withDraw(600);
	B1.withDraw(700);
	cout << "Balance: " << B1.getBalance() << endl;
	//Balance: 147200

	B1.printLastNTransactions();
	//Transactions: -700, -600, -500, -400, -300, -200, -100, 10000, 20000, 30000

	system("pause");
	//Press any key to continue . . .
}