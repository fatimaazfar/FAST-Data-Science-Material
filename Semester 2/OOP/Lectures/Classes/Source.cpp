#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
class timeclock
{
private:
	int hrs;
	int min;
	int sec;
public:
	void input()
	{
		cout << "Enter hours: ";
		cin >> hrs;
		cout << "Enter minutes: ";
		cin >> min;
		cout << "Enter seconds: ";
		cin >> sec;
	}
	void print()
	{
		for (int i = 0;;i++)
		{
			if (_kbhit())
			{
				break;
			}
			if (sec == 60)
			{
				min++;
				sec = 0;
			}
			if (min == 60)
			{
				hrs++;
				min = 0;
			}
			if (hrs == 24)
			{
				hrs = 0;
			}
			cout << hrs << " : " << min << " : " << sec << endl;
			sec++;
			Sleep(1000);
			system("CLS");
		}
	}
};
void main()
{
	timeclock mytime;
	cout << "Set time on your clock: " << endl;
	mytime.input();
	mytime.print();
}	