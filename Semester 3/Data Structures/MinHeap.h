/*
* Abdul Saboor
* L20-1113
* BDS-3A1
* 
* implementation of min heap
*/

#include<iostream>
#include<assert.h>
using namespace std;

template<class k, class v>
class heapItem
{
	k key;
	v value;

	template<class k, class v>
	friend class minHeap;
};

template<class k, class v>
class minHeap
{
	heapItem<k, v>* arr;
	int capacity;
	int totalitems;

public:
	minHeap() :arr(nullptr),capacity(0), totalitems(0) {}
	minHeap(int _capcacity)
	{
		this->capacity = _capcacity;
		while (this->capacity < 1)
		{
			cout << "Please enter a number >1 : ";
			cin >> this->capacity;
		}
		arr = new heapItem<k, v>[this->capacity]; // allocation of memory
		this->totalitems = 0;
	}
	~minHeap()
	{
		delete[] this->arr;
		this->totalitems = this->capacity = 0;
	}
	bool isEmpty()
	{
		return(this->arr == nullptr);
	}

	void insert(k key, v value)
	{
		if (this->totalitems == this->capacity) // code to grow heap
		{
			heapItem<k, v>* temp = new heapItem<k, v>[this->capacity * 2];
			for (int i = 0; i < totalitems; i++)
				temp[i] = this->arr[i];
			delete[] this->arr;
			arr = temp;
			this->capacity *= 2;
		}
		// code to insert key value pair in accordance with keys
		heapItem<k, v>* temp = &this->arr[this->totalitems++];
		temp->key = key;
		temp->value = value;
		
		// reheaping to minimum heap
		int i = this->totalitems - 1; // pointing to last element
		while (i != 0 && (arr + ((i - 1) / 2))->key > (arr+i)->key )
		{
			swap((arr + ((i - 1) / 2))->key, (arr + i)->key);
			swap((arr + ((i - 1) / 2))->value, (arr + i)->value);
			i = (i - 1) / 2;
		} 
	}
	void deleteMin()
	{
		assert(this->totalitems > 0);
		swap(arr->key, (arr + (totalitems-1))->key);
		swap(arr->value, (arr + (totalitems-1))->value);
		this->totalitems--;

		int i=0; // pointing to first element
		while (i <(totalitems-1))
		{
			if ((arr + i)->key > max((arr + ((i * 2) + 1))->key, (arr + ((i * 2) + 2))->key))
			{
				// if left child is lesser than left
				if ((arr + ((i * 2) + 1))->key < (arr + ((i * 2) + 2))->key)
				{
					swap((arr + ((i * 2) + 1))->key, (arr + i)->key);
					swap((arr + ((i * 2) + 1))->key, (arr + i)->key);
					i = ((i * 2) + 1);
				}
				else // if right child is lesser than right
				{
					swap((arr + ((i * 2) + 2))->key, (arr + i)->key);
					swap((arr + ((i * 2) + 2))->key, (arr + i)->key);
					i = ((i * 2) + 2);

				}
			}
		}
	}
	void getMin(v& _value)
	{
		assert(this->totalitems > 0);
		_value = this->arr->value;
	}
};