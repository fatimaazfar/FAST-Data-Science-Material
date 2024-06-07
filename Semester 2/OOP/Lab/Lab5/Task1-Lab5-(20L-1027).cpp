#include<iostream>
using namespace std;
class Event
{
	char* name;
	char* venue;
	char date[11];
	char time[9];
public:
	char* getname()
	{
		char temp[20];
		cout << "Enter the name of the event : ";
		cin.getline(temp, 20);
		int size = strlen(temp);
		name = new char[size + 1];
		for (int i = 0;i <= size;i++)
		{
			name[i] = temp[i];
		}
		return name;
	}
	char* getvenue()
	{
		char temp[50];
		cout << "Enter the venue for the event : ";
		cin.getline(temp, 50);
		int size = strlen(temp);
		venue = new char[size + 1];
		for (int i = 0;i <= size;i++)
		{
			venue[i] = temp[i];
		}
		return venue;
	}
	char* getdate()
	{
		cout << "Enter date for the event in (dd-mm-yyyy) format : ";
		cin.getline(date, 11);
		return date;
	}
	char* gettime()
	{
		cout << "Enter time for the event in (hh:mm am/pm) format : ";
		cin.getline(time, 11);
		return time;
	}
	void setname(const char n[])
	{
		delete[] name;
		int size = strlen(n);
		name = new char[size + 2];
		for (int i = 0;n[i]!='\0';i++)
		{
			name[i] = n[i];
			size = i;
		}
		name[size+1] = '\0';
	}
	void setvenue(const char v[])
	{
		delete[] venue;
		int size = strlen(v);
		venue = new char[size + 2];
		for (int i = 0;v[i]!='\0';i++)
		{
			venue[i] = v[i];
			size = i;
		}
		venue[size+1] = '\0';
	}
	void setdate(const char d[])
	{
		int size = 0;
		for (int i = 0;d[i]!='\0';i++)
		{
			date[i] = d[i];
			size = i;
		}
		date[size + 1] = '\0';
	}
	void settime(const char t[])
	{
		int size = 0;
		for (int i = 0; t[i]!='\0';i++)
		{
			time[i] = t[i];
			size = i;
		}
		time[size + 1] = '\0';
	}
	void userinput()
	{
		getname();
		getvenue();
		getdate();
		gettime();
	}
	void print()
	{
		cout << endl;
		cout << "Event name : " << name << endl;
		cout << "Venue : " << venue << endl;
		cout << "Date : " << date << endl;
		cout << "Time : " << time << endl;
	}
	~Event()
	{
		delete[] name;
		delete[] venue;
	}
	Event();
	Event(char event_name[20], char event_venue[50], char event_date[11], char event_time[9]);
};
Event::Event()
{
	name = nullptr;
	venue = nullptr;
	for (int i = 0; i < 11; i++)
		date[i] = '\0';
	for (int i = 0; i < 9; i++)
		time[i] = '\0';
	cout << "Default Constructor Called." << endl;
}
Event::Event(char event_name[20], char event_venue[50], char event_date[11], char event_time[9])
{
	int name_size = strlen(event_name);
	this->name = new char[name_size + 1];
	for (int i = 0; i < name_size; i++)
		this->name[i] = event_name[i];
	this->name[name_size] = '\0';

	int event_size = strlen(event_venue);
	this->venue = new char[event_size + 1];
	for (int i = 0; i < event_size; i++)
		this->venue[i] = event_venue[i];
	this->venue[event_size] = '\0';

	int date_size = strlen(event_date);
	for (int i = 0; i < date_size; i++)
		this->date[i] = event_date[i];
	this->date[date_size] = '\0';

	int time_size = strlen(event_time);
	for (int i = 0; i < time_size; i++)
		this->time[i] = event_time[i];
	this->time[time_size] = '\0';

	cout << "Overload Constructor Called." << endl;

}
int main()
{
	Event e1;
	e1.userinput();
	e1.print();
	e1.setname("Softec");
	e1.setvenue("FAST NUCES Lahore campus");
	e1.setdate("25-12-2021");
	e1.settime("05:30 pm");
	e1.print();
	return 0;
}