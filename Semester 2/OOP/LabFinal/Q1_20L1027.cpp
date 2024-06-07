#include<iostream>
using namespace std;

//Given is the data members of class Binary. You have to complete the class definition such that the provided main function runs perfectly.
class Binary
{
	//private:
		//int * number;		//an array to sore the 1s and 0s. There should be 1s and 0s only!!!
		//int length;			//length of array
public:
	int* number;		//an array to sore the 1s and 0s. There should be 1s and 0s only!!!
	int length;
	//Create all necessary functions here
	Binary(int* array = nullptr, int length_of_array = 0)//overload and default constructor
	{
		length = length_of_array;
		if (length_of_array != 0)
		{
			number = new int[length_of_array];
			for (int i = 0;i < length; i++)
			{
				number[i] = array[i];
			}
		}
	}
	Binary(const Binary& b)
	{
		length = b.length;
		for (int i = 0;i < b.length; i++)
		{
			number[i] = b.number[i];
		}
	}
	Binary& operator = (Binary& b)
	{
		length = b.length;
		for (int i = 0;i < b.length; i++)
		{
			number[i] = b.number[i];
		}
		return *this;
	}
	friend istream& operator>> (istream& in, Binary& b)
	{
		cout << "Enter Length of Binary number : ";
		in >> b.length;
		b.number = new int[b.length];
		cout << "Enter digits of the number one by one : " << endl;
		for (int i = 0;i < b.length; i++)
		{
		again:
			in >> b.number[i];
			if (b.number[i] != 1 && b.number[i] != 0)
			{
				cout << "Invalid, enter only 1 or 0." << endl;
				goto again;
			}
		}
		return in;
	}

	friend ostream& operator<< (ostream& out, Binary& b)
	{
		cout << "Length of Binary number : ";
		out << b.length << endl;
		if (b.number != nullptr)
		{
			cout << "Binary Number : ";
			for (int i = 0;i < b.length; i++)
			{
				out << b.number[i];
			}
			out << endl;
		}
		return out;
	}

	Binary& operator || (Binary& b)
	{
		Binary obj;
		int smallerlength;//stores length of smaller for further use
		int* temp;//stores the big array for further use
		if (this->length > b.length)//this if else forms a binary object of same size as the bigger obj passed
		{
			obj.number = new int[this->length];
			obj.length = this->length;
			smallerlength = b.length;
			temp = new int[this->length];
			temp = this->number;
		}
		else
		{
			obj.number = new int[b.length];
			obj.length = b.length;
			smallerlength = this->length;
			temp = new int[b.length];
			temp = b.number;
		}
		for (int i = 0; i < smallerlength; i++)
		{
			if (this->number[i] == 1 || b.number[i] == 1)
				obj.number[i] = 1;
			else
				obj.number[i] = 0;
		}
		/*
		in case one binary is greater in size than the other,
		so in 'OR' the smaller binary values that are missing are called "don't care values",
		as a result the greater binary gives its values directly
		the following logic covers this exceptional case:
		*/
		if (b.length > this->length || this->length > b.length)
		{
			for (int i = smallerlength; i < obj.length; i++)
			{
				obj.number[i] = temp[i];
			}
		}
		delete[] temp;
		return obj;
	}

	Binary& operator && (Binary& b)
	{
		Binary obj;
		int smallerlength;//stores length of smaller for further use
		int* temp;//stores the big array for further use
		if (this->length > b.length)//this if else forms a binary object of same size as the bigger obj passed
		{
			obj.number = new int[this->length];
			obj.length = this->length;
			smallerlength = b.length;
			temp = new int[this->length];
			temp = this->number;
		}
		else
		{
			obj.number = new int[b.length];
			obj.length = b.length;
			smallerlength = this->length;
			temp = new int[b.length];
			temp = b.number;
		}
		for (int i = 0; i < smallerlength; i++)
		{
			if (this->number[i] == 1 && b.number[i] == 1)
				obj.number[i] = 1;
			else
				obj.number[i] = 0;
		}
		/*
		in case one binary is greater in size than the other,
		so in 'AND' the smaller binary values that are missing are called "don't care values",
		as same in 'OR'
		as a result the greater binary gives its values directly
		the following logic covers this exceptional case:
		*/
		if (b.length > this->length || this->length > b.length)
		{
			for (int i = smallerlength; i < obj.length; i++)
			{
				obj.number[i] = temp[i];
			}
		}
		delete[] temp;
		return obj;
	}

	Binary& operator ! ()
	{
		Binary obj;
		obj.length = this->length;
		obj.number = new int[obj.length];
		for (int i = 0; i < obj.length;i++)
		{
			if (this->number[i] == 1)
				obj.number[i] = 0;
			else if (this->number[i] == 0)
				obj.number[i] = 1;
		}
		return obj;
	}

	~Binary()
	{
		if (number != nullptr)
			delete[] number;
		number = nullptr;
	}
};

int main()
{
	int a[5] = { 1,0,1,1,0 };
	int b[5] = { 0,1,1,0,1 };
	Binary Num0;
	cin >> Num0;
	cout << Num0;

	Binary Num1(a, 5);
	Binary Num2(b, 5);

	Binary Num3 = Num1 || Num2;
	cout << Num3;				//prints 11111

	Binary Num4;
	Num4 = Num1 && Num3;
	cout << Num4;				//prints 10110

	Num2 = !Num1;
	cout << Num2;				//prints 01001

	system("pause");
}

