#include"List.h"

int main()
{
	List myList;
	myList + 1.2 + 2.3 + 0.5 + 3.5 + 9.2 + 11.6;
	cout << myList << endl;
	cout << myList.length() << endl;
	float item = -myList;
	cout << myList[2.3] << endl;
	myList.reverse();
	cout << myList << endl;
	List myList2;
	myList2 + 2.1 + 3.2 + 4.5 + 0.9;
	myList + myList2;
	cout << myList << endl;
	return 0;
}