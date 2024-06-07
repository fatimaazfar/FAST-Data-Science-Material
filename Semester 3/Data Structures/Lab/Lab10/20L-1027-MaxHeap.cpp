#include<iostream>
using namespace std;

template<typename k, typename v>
struct heapitem
{
public:
	k key;
	v value;
};

template<typename k, typename v>
class maxheap
{
	heapitem<k,v>* arr;
	int capacity;
	int current;
public:
	maxheap(int size = 0):capacity(size),current(0)
	{
		arr = new heapitem<k,v>[capacity];
	}
	void insert(k key, v value)
	{
		if (current != capacity)
		{
			insert:
			arr[current].key = key;
			arr[current].value = value;
			current++;
			heapify(arr, capacity, current);
		}
		else
		{
			capacity *= 2;
			array_increase(capacity);
			goto insert;
		}
	}
	void array_increase(int cap)
	{

	}
	void heapify(heapitem<k,v>* arr, int n, int i)
	{
		int largest = i; // Initialize largest as root
		int l = 2 * i + 1; // left = 2*i + 1
		int r = 2 * i + 2; // right = 2*i + 2

		// If left child is larger than root
		if (l < n && arr[l].key > arr[largest].key)
			largest = l;

		// If right child is larger than largest so far
		if (r < n && arr[r].key > arr[largest].key)
			largest = r;

		// If largest is not root
		if (largest != i) {
			swap(arr[i].key, arr[largest].key);

			// Recursively heapify the affected sub-tree
			heapify(arr, n, largest);
		}
	}
	void print()
	{
		cout << "Capacity : " << capacity << endl << "{ ";
		for (int i = 0;i < capacity; i++)
		{
			cout << "(" << arr[i].key << "," << arr[i].value << ")" << " ";
		}
		cout << "}" << endl;
	}
};

int main()
{
	maxheap<int,int> m(5);
	m.insert(3,3);
	m.insert(2,2);
	m.insert(1,1);
	m.insert(4,4);
	m.insert(5,5);
	m.print();
}