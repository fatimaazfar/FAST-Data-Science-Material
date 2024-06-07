//basic input/output using arithematic operations
#include<iostream>
using namespace std;

float const u = 1.234;//global constants
float const p = 3.334;

float pow(int base, float exp)//function to calculate power of a number
{
	float result = 1;

	while (exp != 0) {
		result *= base;
		--exp;
	}
	return result;
}

float sqr(float num)//function to calculate square root of a number
{
	int squareroot = 0;
	while (squareroot * squareroot < num)
	{
		squareroot += 1;
	}
	if (squareroot * squareroot != num)
		--squareroot;
	return squareroot;
}

float calculate(int i)//calculates the arthematic problem
{
	float result;
	i = pow(i, 3 / 2);
	i = u * i;
	i = i * ((pow(i, 2)) - 1);
	i = sqr(i);
	result = p * i - 2;
	result = sqr(result);
	result += sqr(p * i - 1);
	result = i / result;
	return result;
}

int main()//execution
{
again:
	int i = 0;
	float result;
	cout << "Enter the value of 'i' : ";
	cin >> i;
	result = calculate(i);
	cout << "The result is : " << result << endl;
	cout << "\nEnter:\n1 to repeat the program\n2 to exit : ";
	cin >> i;
	cout << endl;
	if (i == 1)
	{
		goto again;
	}
	else
	{
		return 0;
	}
}