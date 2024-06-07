#include<iostream>
#include<fstream>
using namespace std;

class Car
{
private:
	static int totalCars;	// initialize it yourself
	int model;
	char* make;
	char* name;
	char* color;
public:
	static int GetTotalCars()
	{
		return totalCars;
	}
	void copy(char* destiny,char source[])
	{
		int size = sizeof(source);
		if (destiny != nullptr)
		{
			delete[] destiny;
		}
		destiny = new char[size];
		for (int i = 0;i <= size;i++)
		{
			destiny[i] = source[i];
		}
	}
	Car()
	{
		model = 0;
		color = make = name = 0;
		totalCars++;
	}

	Car(Car& car1) {
		//Copy Constructor
		car1.model = model;
		copy(car1.make, make);
		copy(car1.name, name);
		copy(car1.color, color);
	}

	void SetValues(int _model, char* _make, char* _name, char* _color)
	{
		model = _model;
		make = _make;
		name = _name;
		color = _color;
		//Set the values yourself.
	}

	void PrintListView()
	{
		cout << model << " " << make << " " << name << " " << color << endl;
	}
	void PrintDetailView()
	{
		cout << "Model : " << model << endl;
		cout << "Make : " << make << endl;
		cout << "Name : " << name << endl;
		cout << "Color : " << color << endl;
		cout << "Total number  of cars in system : " << totalCars << endl;
	}
	~Car()
	{
		delete[] name;
		delete[] make;
		delete[] color;
		cout << "Destroying ";
		PrintListView();
	}
	void Input()
	{
		//Do not consume one extra byte on heap
		cout << "Model : ";
		cin >> model;
		char temp[50];
		cout << "Make : ";
		cin.getline(temp, 50);
		copy(make, temp);//copy function to allocate and store char arrays without wasting space
		cout << "Name : ";
		cin.getline(temp, 50);
		copy(name, temp);
		cout << "Color : ";
		cin.getline(temp, 50);
		copy(color, temp);
	}
};
int Car::totalCars = 0;

Car* ReadDataFromFile()
{
	ifstream fin;
	int totalCars = 0;
	char buffer[80];
	int model;
	char make[20];
	char name[20];
	char color[20];


	fin.open("CarsData.txt");
	if (fin.is_open())
	{
		fin >> totalCars;
		//cout << totalCars;
		fin.getline(buffer, 80, '\n');	//We are not saving it
		//cout << buffer << endl;

		Car* carsList = new Car[totalCars];
		int i = 0;
		while (!fin.eof())
		{
			fin >> model;
			fin >> make;
			fin >> name;
			fin >> color;
			//Uncomment this line to check what fin has read
			//cout << model << " " << make << " " << name << " " << color << endl;
			carsList[i].SetValues(model, make, name, color);
			i++;
		}
		return carsList;
	}
	else
	{
		return 0;
	}
}

int main()
{
	Car* carsList = ReadDataFromFile();
	int count = 0;
	if (carsList != 0)
	{

		count = Car::GetTotalCars();	//Calling static function
		cout << "Total Number of Cars in System:\t" << count << endl;
		cout << "\nCars List:\n\n";
		for (int i = 0; i < count; i++)
		{
			carsList[i].PrintListView();
		}
		delete[] carsList;
	}


	cout << "Total Number of Cars in System:\t" << Car::GetTotalCars() << endl << endl << endl;

	Car testCar;
	testCar.Input(); // Take car data from user
	testCar.PrintDetailView();

	cout << "Total Number of Cars in System:\t" << testCar.GetTotalCars() << endl << endl << endl;

}