#include<iostream>
using namespace std;

void fibonnaci(int n, int& fib)
{
	fib += n - (n - 1);
	cout << fib << " ";
	n--;
	if (n > 0)
	{
		fibonnaci(n, fib);
	}
}

int main()
{
	int fib = 0;
	fibonnaci(5, fib);
	cout << fib;
}