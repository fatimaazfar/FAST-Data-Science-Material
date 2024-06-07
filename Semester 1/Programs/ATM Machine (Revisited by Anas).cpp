/*
1- Declare 4 integers varialbe as amt, t5, t1, h5.
2- Check if amt is the multiple of 500.
3- Start with 5000 then goto 1000 then finally to 500 as we have to print least possible number of notes for amt.
4- Divide amt by 5000 to get the number of notes for the value.
5- If the 5000 can give us minimun number of notes than we have to assign 0 to amt so that other variable do not print their values.
6- For that, use this formula: amt = amt - (t5 * 5000)
7- Do the same for the rest of variables respectively.
8- Print number of notes for give amt.
9- I have also made a condition to print only those notes which are going to be given out by the ATM machine.
*/

#include <iostream>
using namespace std;

int main()
{
	int amt, t5, t1, h5;
	cout << "Enter the amount you intend to withdraw: \n";
	cin >> amt;
		t5 = amt / 5000;
		amt = amt - (t5 * 5000);
		t1 = amt / 1000;
		amt = amt - (t1 * 1000);
		h5 = amt / 500;
		amt = amt - (h5 * 500);
		
		if (t5 != 0)
		{
			if (t1 == 0 && h5 == 0)
			cout << "5000 Notes: " << t5 << endl;
			else if (t1 != 0 && h5 == 0)
			cout << "5000 Notes: " << t5 << "\n1000 Notes: " << t1 << endl;
			else if (t1 == 0 && h5 != 0)
			cout << "5000 Notes: " << t5 << "\n500 Notes: " << h5 << endl;
			else if (t1 != 0 && h5 != 0)
			cout << "5000 Notes: " << t5 << "\n1000 Notes: " << t1 << "\n500 Notes: " << h5 << endl;
		}
		
		if (t5 == 0)
		{
			if (t1 != 0 && h5 == 0)
			cout << "1000 Notes: " << t1 << endl;
			else if (t1 == 0 && h5 != 0)
			cout << "500 Notes: " << h5 << endl;
			else if (t1 != 0 && h5 != 0)
			cout << "1000 Notes: " << t1 << "\n500 Notes: " << h5 << endl;
		}
		
	
	system("pause");
	return 0;
}
