#include"datetime.h"
#include<iostream>
#include<string>
using namespace std;

class Task
{
	MyTime Time;
	string description;
public:
	myDate Date;
	Task(int day = 0, int month = 0, int year = 0, int hour = 0, int minute = 0, int second = 0, string descrip = "") :description(descrip)
	{
		if (hour < 25 && hour >= 0 && minute < 61 && minute >= 0 && second < 61 && second >= 0)
			Time.setTime(hour, minute, second);
		else
			cout << "Invalid time entered." << endl;
		if (day < 32 && day > 0 && month < 13 && month > 0 && year > 2000)
			Date.setDate(day, month, year);
		else
			cout << "Ivalid date entered." << endl;
	}

	void print()
	{
		cout << "Date : " << Date << endl;
		cout << "Time : " << Time << endl;
		cout << "Description : " << description << endl;
	}
};

class OneTime : public Task
{
private:
	//no private attributes
public:
	OneTime(int day, int month, int year, int hour, int minute, int second, string descrip)
	{
		Task::Task(day, month, year, hour, minute, second, descrip);
	}
};

class Recurring : public Task
{
private:
	int repitition_gap;		//Daily task = 1 or weekly = 2 or monthly= 3
public:
	Recurring(int day, int month, int year, int hour, int minute, int second, string descrip, int r)
	{
		Task::Task(day, month, year, hour, minute, second, descrip);
		repitition_gap = r;
	}
	void PrintNextDay()	//Print the date when it'll re-occur. In case of Daily, prints next date; for weeklym prints date of next week, for monthly, prints date of next month
	{
		myDate next;
		if (repitition_gap == 1)
		{
			next.setDate(Date.getday() + 1, Date.getmonth(), Date.getyear());
		}
		else if (repitition_gap == 2)
		{
			next.setDate(Date.getday(), Date.getmonth() + 1, Date.getyear());
		}
		else if (repitition_gap == 3)
		{
			next.setDate(Date.getday(), Date.getmonth(), Date.getyear() + 1);
		}
	}
};


class DailyList
{
private:
	Task** ListOfTasks;		//Lists of tasks for that day. Should it be a pointer? an object? decide yourself
	int numOfTasks;
	int capacity;				//max tasks a day can hold. set it to 2 per day.
public:

};

class ToDoList
{
	DailyList** Year2021;		//Year2021 is the collection of DailyList for all 12 months. Should it be a pointer? an object? what will be its type?
public:
	ToDoList()
	{
		for (int i = 0;i < 12;i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				Year2021[i] = new DailyList[31];
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				Year2021[i] = new DailyList[30];
			else
				Year2021[i] = new DailyList[28];
		}
	}
	void AddTask(Task* T)//Add task to said date in calander
	{
		for (int i = 0;i < 12;i++)
		{

		}
	}
	void GetSchedule(myDate Starting, myDate Ending)			//print all tasks that are between 2 dates.
	{

	}
};


int main()
{
	Task T1(12, 06, 2021, 08, 0, 0);		//Design task class such that this line gives error
	OneTime T1(23, 06, 2021, 21, 0, 0, "Prepare for OOP Lab Final"); //Task for 18 06 2021 at 09:00:00 pm
	OneTime T2(26, 06, 2021, 14, 0, 0, "OOP Lab Final");
	Recurring T3(18, 06, 2021, 13, 0, 0, "Lunch Break", 1);		//1 means it'll recurr every day.
	OneTime T4(26, 06, 2021, 16, 0, 0, "Post Exam Party");
	OneTime T5(26, 06, 2021, 19, 0, 0, "Dinner with Friends");

	Task* T[3];
	T[0] = &T1;
	T[1] = &T2;
	T[2] = &T3;

	ToDoList MyList;

	for (int i = 0;i < 3;i++)
	{
		T[i]->print();
		MyList.AddTask(T[i]);
	}

	MyList.AddTask(&T4);
	MyList.AddTask(&T5);		//Must not be able to add third task on same day as capacity is of 2 tasks

	myDate D1(06, 06, 2021);
	myDate D2(24, 06, 2021);


	MyList.GetSchedule(D1, D2);

}

//Following lines might help you save some time
//		for(int i=0;i<12;i++)
//		{
//			if(i==1 || i==3 || i==5||i==7||i==8||i==10||i==12)
//				Year2021[i]=new DailyList[31];
//			else if (i==4||i==6||i==9||i==11)
//				Year2021[i]=new DailyList[30];
//			else
//				Year2021[i]=new DailyList[28];
//		}
