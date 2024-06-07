#include<iostream>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node <T>* next;
	Node <T>* prev;
	Node(T d = 0, Node<T>* n = nullptr, Node<T>* p = nullptr) : next(n), prev(p), data(d) {}
};

template <class T>
class dlist
{
public:
	Node <T>* head;
	Node <T>* tail;
	dlist() : tail(new Node<T>), head(new Node<T>)
	{
		head->next = tail;
		head->prev = nullptr;
		tail->prev = head;
		tail->next = nullptr;
	}
	void insertStart(T const element)
	{
		if (head->next == tail)
		{
			head->next = new Node<T>;
			head->next->data = element;
			head->next->prev = head;
			tail->prev = head->next;
		}
		else
		{
			Node<T>* temp = head->next;
			head->next = new Node<T>;
			head->next->next = temp;
			temp->prev = head->next;
			head->next->data = element;
			head->next->prev = head;
		}
	}

	void insertEnd(T const element)
	{
		if (head->next == tail)
		{
			head->next = new Node<T>;
			head->next->data = element;
			head->next->prev = head;
			tail->prev = head->next;
		}
		else
		{
			Node<T>* temp = new Node<T>;
			tail->prev->next = temp;
			temp->data = element;
			temp->next = tail;
			temp->prev = tail->prev;
			tail->prev = temp;
			tail->next = nullptr;
		}
	}

	void print()
	{
		Node<T>* temp = head->next;
		while (temp != tail)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void deleteNode(Node<T>* t)
	{
		Node<T>* temp = head->next;
		while (temp != tail)
		{
			if (temp->next == t)
			{
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete t;
			}
			temp = temp->next;
		}
	}

	void deletevalue(T const v)
	{
		Node<T>* temp = head->next;
		while (temp != tail)
		{
			if (temp->data == v)
			{
				Node<T>* t = temp;
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete t;
			}
			temp = temp->next;
		}
	}

	void addnodeafter(Node<T>* t, T const v)
	{
		Node<T>* temp = head->next;
		while (temp != tail)
		{
			if (temp == t)
			{
				/*Node<T>* temp2 = temp->next;
				temp->next = new Node<T>;
				temp->next->next = temp2->next;
				temp->next->prev = temp2;
				temp->next->data = v;*/

			}
			temp = temp->next;
		}
	}

};

int main()
{
	dlist<int> l;
	l.insertStart(1);
	l.insertStart(2);
	l.insertStart(3);
	l.insertEnd(0);
	l.insertEnd(-1);
	cout << "Add in end and start : ";
	l.print();
	cout << endl;
	cout << "Delete node : ";
	l.deleteNode(l.head->next->next);//deletes 2
	l.print();
	cout << endl;
	cout << "Add between : ";
	l.addnodeafter(l.head->next->next, 10);
	l.print();
	cout << endl;
}