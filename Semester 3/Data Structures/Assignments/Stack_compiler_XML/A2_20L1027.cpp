#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
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
        Node<T>* temp = head->next;
        while (temp != tail)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }
};

template <typename T>
class Stack
{
    Singly<T> s;
    int size;
public:
    Stack() :size(0) {}
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

class XMLdata
{
    char type;
    string name;
public:
    XMLdata(char typ = 'x', string nam = ""):type(typ),name(nam)
    {}
    void setType(char typ)
    {
        type = typ;
    }
    void setName(string nam)
    {
        name = nam;
    }
    string getName()
    {
        return name;
    }
    XMLdata operator = (const XMLdata& x) // assignment operator
    {
        this->name = x.name;
        this->type = x.type;
        return *this;
    }
    XMLdata(const XMLdata& x) // copy constructor
    {
        this->name = x.name;
        this->type = x.type;
    }
    bool operator == (const XMLdata& x) const // compares if both are open and close of same named tag
    {
        if (x.name == this->name)
        {
            if (x.type == 'o')
            {
                if (this->type == 'c')
                {
                    return true;
                }
            }
            else if (x.type == 'c')
            {
                if (this->type == 'o')
                {
                    return true;
                }
            }
        }
        return false;
    }
    friend ostream& operator << (ostream& out, const XMLdata& x)
    {
        if (x.type == 'o')
        {
            out << "<" << x.name << ">";
        }
        else if (x.type == 'c')
        {
            out << "</" << x.name << ">";
        }
        return out;
    }
    void print()
    {
        if (type == 'o')
        {
            cout << "<" << name << ">" << endl;
        }
        else if (type == 'c')
        {
            cout << "</" << name << ">" << endl;
        }
    }
};

string readFile(string file_path)
/* reads all of data from the file into a single string */
{
    string file;
    ifstream fin(file_path);
    if (!fin.is_open())
    {
        cerr << "Could Not open the file." << file_path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    file = string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    return file;
}

bool CheckTags(Stack<XMLdata> &tags, string code)
/* 
   stores all the opening tags in stack and when a closing tag is detected it pops the opening tag for it
   from the stack, if the stack ends up empty then the code doesn't have errors, else it mentions the earlier error
   for prologue and comments it only checks the opening brackets and closing brackets, if they exist
   it won't print any error. It also detects if there is a missing bracket as in '<' is not present in 
   the starting of a new line or '>' is not there in the end of a tag name 
*/
{
    int line_num = 1, count = 0;
    for (int i = 0;i < code.size();i++) // loop runs for the whole code character by character
    {
        if (code[i] == '\n') // keeps check of the line number
            line_num++;
        if (code[i] == '\n' && code[i + 1] != '<') // keeps check of the opening brackets '<'
        {
            cout << "Error in opening bracket of a tag on line no. " << line_num + 1 << endl;
            count++;
        }
        if (code[i] == '<') // if it finds an opening bracket
        {
            i++;
            if (code[i] == '?' && line_num == 1) // is it a prologue?
            {
                i++;
                while (code[i] != '?' || code[i + 1] != '>') // pass it on till you've reached the closing brackets
                {
                    i++;
                    if (code[i] == '\n') // if the line has ended and you didn't find any closing, it's an error
                    {
                        cout << "Error in the closing of prologue on line no. " << line_num << endl;
                        count++;
                        break;
                    }
                }
            }
            else if (code[i] == '?' && line_num != 1)
                cout << "Prologue can only exist on line no. 1, error on line no. " << line_num << endl;
            else if (code[i] == '!' && code[i + 1] == '-' && code[i + 2] == '-') // is it a comment?
            {
                i += 3;
                while (code[i] != '-' || code[i + 1] != '>') // pass it on till you've reached the closing brackets
                {
                    i++;
                    if (code[i] == '\n') // if the line has ended and you didn't find any closing, it's an error
                    {
                        cout << "Error in the closing of comment on line no. " << line_num << endl;
                        count++;
                        break;
                    }
                    else if (code[i] == '-' && code[i + 1] != '-' && code[i + 2] == '>')
                    {
                        cout << "Error in closing of comment on line no. " << line_num << endl;
                        count++;
                        break;
                    }
                    else if (code[i] != '-' && code[i + 1] == '-' && code[i + 2] == '>')
                    {
                        cout << "Error in closing of comment on line no. " << line_num << endl;
                        count++;
                        break;
                    }
                }
            }
            else if (code[i] == '!' && (code[i + 1] != '-' || code[i + 2] != '-'))
            {
                cout << "Error in the opening of the comment on line no. " << line_num << endl;
                count++;
            }
            else if (code[i] == '/') // is it a closing tag?
            {
                string name;
                i++;
                while (code[i] != '>') // store its name in a string till the closing bracket arrives
                {
                    name += code[i];
                    i++;
                }
                XMLdata x;
                tags.top(x);
                if (x.getName() == name) // match this name with the top most opening tag in stack
                {
                    tags.pop(); // if it matches then pop the top opening tag
                }
                else
                {
                    cout << "Could not find the closing tag for " << x.getName() << " on line no. " << line_num << endl;
                    count++;
                    tags.pop();
                }
            }
            else // is it an opening tag?
            {
                string name;
                while (code[i] != '>') // store only the name of the tag (no matter its an attribute/text/element tag)
                {
                    name += code[i];
                    i++;
                    if (code[i] == ' ')
                        break;
                }
                tags.push(XMLdata('o', name)); // push its xml data in the stack
                if (code[i] == ' ')
                    goto attribute;
                else
                    goto exit;
            attribute:
                    i++;
                    if (code[i] == '=' && code[i + 1] != '"')
                    {
                        cout << "No opening quotation on line no. " << line_num << endl;
                        count++;
                        i += 2;
                    }
                    else if (code[i] == '"' && code[i - 1] != '=')
                    {
                        cout << "No '=' found in attribute tag on line no. " << line_num << endl;
                    }
                    else if (code[i] == '=' && code[i + 1] == '"')
                    {
                        i += 2;
                        while (code[i] != '>')
                        {
                            i++;
                            if (code[i] == '>' && code[i - 1] != '"')
                            {
                                cout << "No closing quotation on line no. " << line_num << endl;
                                count++;
                                break;
                            }
                            else if (code[i] == '"' && code[i + 1] != '>')
                            {
                                cout << "No closing bracket found for tag " << name << " on line no. " << line_num << endl;
                                count++;
                                break;
                            }
                            else if (code[i] == '\n')
                            {
                                cout << "No proper closing found for tag " << name << " on line no. " << line_num << endl;
                                count++;
                                break;
                            }
                            else if (code[i] == '"' && code[i + 1] == '>')
                            {
                                cout << "Sab sahi hy boss" << endl;
                                break;
                            }
                            else
                            {
                                cout << "wtf man" << endl;
                            }
                        }
                    }
                exit:
                    cout << "";
            }
        }
        else if (code[i] == '/' && code[i - 1] != '<')
        {
            cout << "No opening bracket found for closing tag on line no. " << line_num << endl;
            count++;
        }
    }
    cout << "Program exited." << endl;
    if (tags.isEmpty() && count == 0) // if the stack is empty then there are no errors
    {
        cout << "No errors detected." << endl;
        return true;
    }
    else // else errors are present
    {
        if (count == 1)
            cout << count << " error was detected." << endl;
        else if (count > 0)
            cout << count << " errors were detected." << endl;
        else if (count == 0)
        {
            cout << "Stack was not empty." << endl;
            tags.print();
        }
        return false;
    }
}

int main()
{
    Stack<XMLdata> tags;
    string code_file = readFile("xmlcode.txt");
    CheckTags(tags, code_file);
}