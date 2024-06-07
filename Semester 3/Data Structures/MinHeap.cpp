#include<iostream>
#include"lab10-20l1027.h"
using namespace std;

int main()
{
	minHeap<int, int> h2(5);
	h2.insert(2, 4);
	h2.insert(1, 5);
	int x;
	h2.getMin(x);
	h2.deleteMin();
	h2.deleteMin();
	//h2.deleteMin();
	cout << x << endl;
	
	system("pause");
	return 0;
}