#include<iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node(T d = 0, Node<T>* n = nullptr) :data(d), next(n)
    {}
    Node(const Node<T>& obj)
    {
        this->data = obj.data;
    }
};

template <class T>
class Singly
{
public:
    Node<T>* head;
    Node<T>* tail;
    Singly() :head(new Node<T>), tail(new Node<T>)
    {
        head->next = tail;
    }

    void insertAtStart(T dat)
    {
        Node<T>* temp = head->next;
        head->next = new Node<T>;
        head->next->data = dat;
        head->next->next = temp;
    }

    void insertAtEnd(T dat)
    {
        tail->data = dat;
        tail->next = new Node<T>;
        tail = tail->next;
    }

    void insertAfter(const T dat, const T dat2)
    {
        Node<T>* temp = head->next;
        while (temp != tail)
        {
            if (temp->next != tail && temp->data == dat)
            {
                Node<T>* tmp = temp->next->next;
                temp->next = new Node<T>;
                temp->next->next = tmp;
                temp->next->data = dat2;
            }
            else if (temp->next == tail && temp->data == dat)
            {
                this->insertAtEnd(dat2);
            }
            temp = temp->next;
        }
    }

    void delFromStart()
    {
        if (head->next != tail)
        {
            Node<T>* temp = head->next->next;
            delete head->next;
            head->next = temp;
        }
        else
        {
            cout << "The singly list is empty." << endl;
        }
    }

    void delFromEnd()
    {
        if (head->next != tail)
        {
            if (head->next->next == tail)
            {
                delete head->next;
                head->next = tail;
            }
            else
            {
                Node<T>* temp = head->next;
                while (temp != tail)
                {
                    if (temp->next->next == tail)
                    {
                        delete temp->next;
                        temp->next = tail;
                    }
                    temp = temp->next;
                }
            }
        }
        else
            cout << "Empty list" << endl;
    }

    T last_element_data()
    {
        Node<T>* temp = head->next;
        T dat = 0;
        while (temp != tail)
        {
            dat = temp->data;
            temp = temp->next;
        }
        return dat;
    }

    void delAfter(const T dat)
    {
        Node<T>* temp = head->next;
        while (temp != tail)
        {
            if (temp->data == dat)
            {
                Node<T>* tmp = temp->next->next;
                delete temp->next;
                temp->next = tmp;
            }
            temp = temp->next;
        }
    }

    void print()
    {
        cout << "{ ";
        Node<T>* temp = head->next;
        while (temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "}";
    }
};

template <typename T>
class Stack
{
	Singly<T> s;
    int size;
public:
	Stack():size(0){}
	void pop()
	{
        s.delFromEnd();
        size--;
	}
	void push(T dat)
	{
        s.insertAtEnd(dat);
        size++;
	}

    int get_size()
    {
        return size;
    }

    bool isEmpty()
    {
        if (s.head->next == s.tail)
        {
            return true;
        }
        return false;
    }

    bool top(T& e)
    {
        if (!isEmpty())
        {
            e = s.last_element_data();
            return true;
        }
        return false;
    }
    void print()
    {
        s.print();
    }
};

bool isBalanced(string exp)
{
    Stack<char> a;
    char data = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            a.push('(');
        }
        else if (exp[i] == '[')
        {
            a.push('[');
        }
        else if (exp[i] == '{')
        {
            a.push('{');
        }
        else if (exp[i] == ')')
        { 
            a.top(data);
            if (data == '(')
            {
                a.pop();
            }
            else
                return false;
        }
        else if (exp[i] == ']')
        {
            a.top(data);
            if (data == '[')
            {
                a.pop();
            }
            else
                return false;
        }
        else if (exp[i] == '}')
        {
            a.top(data);
            if (data == '{')
            {
                a.pop();
            }
            else
                return false;
        }
    }
    if(a.isEmpty())
        return true;
}

string reverse(string const str)
{
    Stack<char> rev;
    const int s = str.size();
    for (int i = 0; i < s;i++)
    {
        rev.push(str[i]);
    }
    string reversed;
    char dat;
    for (int i = 0; i < s ;i++)
    {
        rev.top(dat);
        cout << dat;
        //reversed.append();
        rev.pop();
    }
    return reversed;
}

int main()
{
    Stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.print();
    cout << endl;
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.print();
    cout << endl;
    bool res = isBalanced("{}[][()]");
    if (res == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    reverse("Fatima");
}