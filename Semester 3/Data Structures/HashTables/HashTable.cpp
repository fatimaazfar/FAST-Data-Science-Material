#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

template<class v>
class HashItem
{
public:
	int key;
	v value;
	HashItem<v>* next;
	HashItem()
	{
		key = 0;
		next = nullptr;
		value = NULL;
	}
	HashItem(int k, v val)
	{
		key = k;
		value = val;
		next = nullptr;
	}
	void operator = (const HashItem<v>& h)
	{
		this->key = h.key;
		this->value = h.value;
		this->next = h.next;
	}

	template<class v>
	friend class HashMap;
};

template <class v>
class HashMap
{
	vector<HashItem<v>> hashVector;
	int currentElements;
	int capacity;
public:
	HashMap()
	{
		hashVector.resize(10);
		capacity = 10;
		currentElements = 0;
		for (int i = 0;i < capacity;i++)
			hashVector.push_back(HashItem<v>());
	}
	HashMap(int const cap)
	{
		assert(cap > 1);
		hashVector.resize(cap);
		currentElements = 0;
		capacity = cap;
	}
	void insert(int const key, v const value)
	{
		int x = key % capacity;
		{
			if (hashVector[x].next == nullptr)
				hashVector[x].next = new HashItem<v>(key, value);
			else
			{
				HashItem<v>* temp = hashVector[x].next;
				while (temp != nullptr)
				{
					if (temp->next == nullptr)
					{
						temp->next = new HashItem<v>(key, value);
						break;
					}
					temp = temp->next;
				}
			}
		}
	}
	void print()
	{
		for (int i = 0;i < capacity;i++)
		{
			cout << "(" << i << ") ";
			if (hashVector[i].next != nullptr)
			{
				HashItem<v>* temp = hashVector[i].next;
				while (temp != nullptr)
				{
					cout << temp->key << " ";
					temp = temp->next;
				}
			}
			cout << endl;
		}
	}
	bool deleteKey(int const k) const
	{
		int x = k % capacity;
		HashItem<v>* temp = hashVector[x].next;
		if (temp->key == k)
		{
			hashVector[x].next = hashVector[x].next->next;
			delete temp;
		}
		while (temp != nullptr)
		{
			if (temp->next->key == k)
			{
				HashItem<v>* t = temp->next->next;
				delete temp->next;
				temp->next = nullptr;
				temp->next = t;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	v* get(int const k) const
	{
		int x = k % capacity;
		HashItem<v>* temp = hashVector[x].next;
		while (temp != nullptr)
		{
			if (temp->key == k)
			{
				return temp->value;
			}
			temp = temp->next;
		}
		return nullptr;
	}
	void deleteChain(HashItem<v>* &h)
	{
		if (h)
		{
			deleteChain(h->next);
			delete h->next;
			h->next = nullptr;
		}
	}
	void clear()
	{
		for (int i = 0;i < capacity;i++)
		{
			if (hashVector[i].next != nullptr)
			{
				deleteChain(hashVector[i].next);
			}
		}
	}
	~HashMap()
	{
		clear();
		hashVector.clear();
	}
};

int main()
{
	HashMap<int> h(10);
	h.insert(10,2);
	h.insert(11,2);
	h.insert(12,2);
	h.insert(13,2);
	h.insert(23,2);
	h.insert(14,2);
	h.insert(24,2);
	h.insert(34,2);
	h.insert(15,2);
	h.insert(5,2);
	h.insert(6,2);
	h.insert(17,2);
	h.insert(18,2);
	h.insert(20,2);
	h.insert(21,2);
	h.insert(22,2);
	h.insert(32,2);
	h.insert(44,2);
	h.insert(9,2);
	h.insert(19,2);
	h.print();
	h.deleteKey(20);
	h.deleteKey(24);
	cout << endl;
	h.print();
	return 0;
}