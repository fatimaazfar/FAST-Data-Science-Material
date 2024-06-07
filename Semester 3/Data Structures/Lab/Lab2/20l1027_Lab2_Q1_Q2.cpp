#include<iostream>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node <T>* next;
	Node <T> () :data(0), next(0)//default constructor
	{}
	Node <T> (T d, Node <T>* n) :data(d), next(n)///overload constructor
	{}
};

template <class T>
class LinkList
{
public:
	Node <T>* head;
	Node <T>* tail;
	LinkList<T> () :head(0), tail(0)
	{}
	LinkList<T> (Node <T>* h, Node <T>* t) :head(h), tail(t)
	{}
	void insertAtStart(T const element)
	{
		if (head == nullptr)
		{
			head = tail = new Node<T>;
			head->data = element;
			head->next = nullptr;
		}
		else
		{
			Node <T>* temp = head;
			head = new Node<T>;
			head->next = temp;
			head->data = element;
		}
	}
	void insertAtEnd(T const element)
	{
		if (tail != nullptr)
		{
			Node <T>* temp = tail;
			tail = new Node<T>;
			temp->next = tail;//because the last element is being pointed at by the tail pointer as well as the next pointer of the second last element
			temp->next->data = element;
			temp->next->next = nullptr;
		}
		else
		{
			cout << "Invalid Argument." << endl;
		}
	}
	void print() const
	{
		if (head != nullptr)
		{
			Node <T>* temp = head;
			cout << "Linked List : [ ";
			while (temp->next != nullptr)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << "]" << endl;
		}
		else
			cout << "The linked list is empty.";
	}
	bool search(T const& element) const
	{
		if (head != nullptr)
		{
			Node <T>* temp = head;
			while (temp->next != nullptr)
			{
				if (temp->data == element)
				{
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
		else
		{
			cout << "The array is empty.";
			return false;
		}
	}
	bool isEmpty() const
	{
		if (head != nullptr)
		{
			return false;
		}
		else
		{
			cout << "The array is empty.";
			return true;
		}
	}
	void insertBefore(T const v1, T const v2) const//insert value v1 before value v2
	{
		if (head != nullptr)
		{
			int counter = 0;
			Node <T>* temp = head;
			Node <T>* temp2 = nullptr;
			while (temp->next != nullptr)
			{
				if (counter == 1)
				{
					temp2 = head;
				}
				if (temp->data == v2 && counter != 0)
				{
					temp2->next = new Node<T>;
					temp2->next->next = temp;
					temp2->next->data = v1;
				}
				else if (temp->data == v2 && counter == 0)
				{
					//insertAtStart(v1);
				}
				temp = temp->next;
				if (temp2 != nullptr)
					temp2 = temp2->next;
				counter++;
			}
		}
		else
		{
			cout << "The array is empty.";
		}
	}
	void deleteAll(T const value)
	{
		int counter = 0;
		if (head != nullptr)
		{
			Node <T>* temp = head;
			Node <T>* temp2 = nullptr;
			while (temp->next != nullptr)
			{
				if (counter == 1)
				{
					temp2 = head;
				}
				if (temp->data == value && counter != 0)
				{
					Node <T>* t = temp2->next;
					temp2->next = temp->next;
					delete t;
				}
				else if (temp->data == value && counter == 0)
				{
					DeleteAtStart();
				}
				temp = temp->next;
				if (temp2 != nullptr)
					temp2 = temp2->next;
				counter++;
			}
		}
		else
			cout << "The linked list is empty.";
	}
	void DeleteAtStart()
	{
		if (head != nullptr)
		{
			Node <T>* temp = head;
			head = temp->next;
			delete temp;
		}
	}
	~LinkList <T> ()
	{
		if (head != nullptr)
		{
			while (head->next != nullptr)
			{
				DeleteAtStart();
			}
		}
	}
};

template <typename t>
t mode(LinkList<t> l)
{
	int number = l.head->data;
	int mode = number;
	int count = 1;
	int countMode = 1;

	Node<t>* temp = l.head;
	while (temp->next != nullptr)
	{
		if (temp->data == number)
		{ 
			++count;
		}
		else
		{ 
			if (count >= countMode)
			{
				countMode = count;
				mode = temp->data;
			}
			count = 1;
			number = temp->data;
		}
		temp = temp->next->next;
	}
	return mode;
}

template<typename t>
t median(LinkList<t> l)
{
	Node<t>* slow_ptr = l.head;
	Node<t>* fast_ptr = l.head;
	Node<t>* pre_of_slow = l.head;

	if (l.head != NULL) {
		while (fast_ptr != NULL && fast_ptr->next != NULL) {
			fast_ptr = fast_ptr->next->next;
			pre_of_slow = slow_ptr;
			slow_ptr = slow_ptr->next;
		}
		if (fast_ptr != NULL)
			return slow_ptr->data;
		else
			return float(slow_ptr->data + pre_of_slow->data) / 2;
	}
}

template<typename t>
t range(LinkList<t> l)
{
	if (l.head != nullptr)
	{
		t largest = l.head->data;
		t smallest = l.head->data;
		Node<t>* temp = l.head;
		while (temp->next != nullptr)
		{
			if (temp->data > largest)
			{
				largest = temp->data;
			}
			else if (temp->data <= smallest)
			{
				smallest = temp->data;
			}
			temp = temp->next;
		}
		return largest - smallest;
	}
}

int main()
{
	cout << "----------------QUESTION 1-----------------" << endl;

	LinkList <int> myList;
	myList.insertAtStart(2);
	myList.insertAtStart(6);
	myList.insertAtStart(7);
	myList.insertAtEnd(9);
	myList.insertAtEnd(7);
	myList.insertAtEnd(8);
	myList.insertAtStart(9);
	myList.print();
	//myList.deleteAll(7);
	//myList.print();
	myList.insertBefore(10, 6);
	myList.print();
	cout << "searching for 10 :";
	cout << ((myList.search(10)) ? "Found " : "Not Found") << endl;
	cout << "searching for 11 :";
	cout << ((myList.search(11)) ? "Found " : "Not Found") << endl;
	myList.DeleteAtStart();
	myList.print();

	cout << "----------------QUESTION 2-----------------" << endl;
	
	LinkList <int> list2;
	list2.insertAtStart(90);
	list2.insertAtEnd(94);
	list2.insertAtEnd(53);
	list2.insertAtEnd(68);
	list2.insertAtEnd(79);
	list2.insertAtEnd(94);
	list2.insertAtEnd(53);
	list2.insertAtEnd(65);
	list2.insertAtEnd(87);
	list2.insertAtEnd(90);
	list2.insertAtEnd(70);
	list2.insertAtEnd(69);
	list2.insertAtEnd(65);
	list2.insertAtEnd(89);
	list2.insertAtEnd(85);
	list2.insertAtEnd(53);
	list2.insertAtEnd(47);
	list2.insertAtEnd(61);
	list2.insertAtEnd(27);
	list2.print();
	cout << "Mode : " << mode(list2) << endl;
	//cout << "Median : " << median(list2) << endl;
	//cout << "Range : " << range(list2) << endl;
	system("pause");
	return 0;
}