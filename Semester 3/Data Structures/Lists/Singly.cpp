#include <iostream>
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
    Node<T>* head;
    Node<T>* tail;
public:
    Singly() :head(new Node<T>), tail(new Node<T>)
    {
        head->next = tail;
    }

    void insertAtStart(T dat)
    {
        if (head != nullptr && tail != nullptr)
        {
            Node<T>* temp = head->next;
            head->next = new Node<T>;
            head->next->data = dat;
            head->next->next = temp;
        }
    }

    void insertAtEnd(T dat)
    {
        if (head != nullptr && tail != nullptr)
        {
            tail->data = dat;
            tail->next = new Node<T>;
            tail = tail->next;
        }
    }

    void insertAfter(const T dat, const T dat2)
    {
        if (head != nullptr && tail != nullptr && head->next != tail)
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
    }

    void delFromStart()
    {
        if (head != nullptr && tail != nullptr && head->next != tail)
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
    }

    void delFromEnd()
    {
        if (head != nullptr && tail != nullptr && head->next != tail)
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

    void delAfter(const T dat)
    {
        if (head != nullptr && tail != nullptr && head->next != tail)
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
    }

    void print()
    {
        cout << "{ ";
        if (head != nullptr && tail != nullptr && head->next != tail)
        {
            Node<T>* temp = head->next;
            while (temp != tail)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << "}";
    }

    void clear()
    {
        if (head != nullptr && tail != nullptr && head->next != tail)
        {
            Node<T>* temp = head->next;
            while (temp->next != tail)
            {
                temp = head->next->next;
                delete head->next;
                head->next = temp;
            }
        }
    }

    ~Singly()
    {
        clear();
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
};


int main()
{
    Singly<int>s;
    s.insertAtStart(1);
    s.insertAtStart(2);
    s.insertAtStart(3);
    s.insertAfter(3, 4);
    s.insertAtStart(5);
    s.insertAtEnd(0);
    s.insertAtEnd(-1);
    s.insertAfter(-1, -2);
    s.insertAfter(-2, -3);
    s.print();
    cout << endl;
    s.clear();
    s.~Singly();
    s.print();
}