#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<fstream>
using namespace std;

class userData //this class is the data type of all the data in the nodes of the priority queue
{
	int key; //the priority of the user
	int userID; //the ID of the user
	char operation; //read(r) or write(w)
public:
	userData(int k = 0, int id = 0, char oper = 'x'): key(k),userID(id),operation(oper){}//default and overload constructor
	userData(const userData& u)//copy constructor
	{
		this->key = u.key;
		this->userID = u.userID;
		this->operation = u.operation;
	}
	void insert(int k, int id, char oper)
	{
		this->key = k;
		this->userID = id;
		this->operation = oper;
	}
	friend ostream& operator << (ostream& out, userData const& u)
	{
		if (u.operation != 'x')
		{
			out << "{Key:" << u.key << " ID:" << u.userID << " Status:";
			if (u.operation == 'r')
				out << "Read";
			else if (u.operation == 'w')
				out << "Write";
			else
				out << "N/A";
			out << "}";
		}
		return out;
	}
	void print()
	{
		cout << "{Key:" << key << " ID:" << userID << " Status:";
		if (operation == 'r')
			cout << "Read";
		else if (operation == 'w')
			cout << "Write";
		else
			cout << "N/A";
		cout << "}";
	}
	bool operator > (userData& u)
	{
		//100 is a reserved integer that represents the highest priority
		//0 is reserved as the lowest priority so always return false
		if (this->key > u.key)
			return true;
		return false;
	}
	bool operator < (userData& u)
	{
		//100 is a reserved integer that represents the highest priority
		//0 is reserved as the lowest priority so always return false
		if (this->key < u.key)
			return true;
		return false;
	}
	userData operator = (userData& u)
	{
		this->key = u.key;
		this->userID = u.userID;
		this->operation = u.operation;
		return *this;
	}
	bool operator == (userData& u)
	{
		if (this->userID == u.userID && this->operation == u.operation)
			return true;
		return false;
	}
	char getop()
	{
		return operation;
	}
	int getprior()
	{
		return key;
	}
	int getID()
	{
		return userID;
	}
	~userData()
	{
		this->key = NULL;
		this->userID = NULL;
		this->operation = 'x';
	}

	template<class T>
	friend class File;
};

bool isReader(userData u)
{
	if (u.getop() == 'r')
		return true;
	return false;
}

bool inRange(userData u)
{
	if (u.getID() >= 0 && u.getID() <= 10000)
	{
		if (u.getprior() >= 0 && u.getprior() <= 100)
			return true;
		else
			cout << "Invalid Priority key. (Range: 0-100)" << endl;
	}
	else
		cout << "Invalid User ID. (Range: 0-10000)" << endl;
	return false;
}

template<class T>
class PriorityQueue //implemented as maxheap (the largest element is always at the last index)
{
	vector<T> data; //vector array with each node of userData datatype
	int PARENT(int i) {
		return (i - 1) / 2;
	}
	int LEFT(int i) {
		return (2 * i + 1);
	}
	int RIGHT(int i) {
		return (2 * i + 2);
	}
	void heapify_down(int i)
	{
		int left = LEFT(i);
		int right = RIGHT(i);

		int largest = i;

		if (left < size() && data[left] > data[i]) {
			largest = left;
		}

		if (right < size() && data[right] > data[largest]) {
			largest = right;
		}

		if (largest != i)
		{
			T temp = data[i];
			data[i] = data[largest];
			data[largest] = temp;
			heapify_down(largest);
		}
	}
	void heapify_up(int i)
	{
		if (i && data[PARENT(i)] < data[i])
		{
			T temp = data[i];
			data[i] = data[PARENT(i)];
			data[PARENT(i)] = temp;

			heapify_up(PARENT(i));
		}
	}
public:
	PriorityQueue(int id = 0) //default constructor
	{ 
		data.clear(); 
		data.resize(0);
	}
	PriorityQueue(const PriorityQueue& p)//copy constructor
	{
		this->data = p.data;
	}
	bool searchUser(T u)
	{
		if (data.empty() == false)
		{
			for (auto i = data.begin();i != data.end();i++)
			{
				if ((*i) == u)
				{
					return true;
				}
			}
		}
		return false;
	}
	void insert(T u)//insert a single element
	{
		if (searchUser(u) == false) //check if a same user with same operation is accessing that file again and again
		{
			data.push_back(u);
			int index = size() - 1;
			heapify_up(index);
		}
	}
	void buildQueue(T arr[],int size)//takes an unsorted array and converts it into a priority queue
	{
		data.clear();
		//data.resize(0);
		for (int i = 0;i < size;i++)
		{
			data.push_back(arr[i]);
			int index = data.size() - 1;
			heapify_up(index);
		}
	}
	T extractMax()//remove and return the maximum priority user
	{
		T max = data[0];
		data[0] = data.back();
		data.pop_back();
		heapify_down(0);
		return max;
	}
	T findMax()//return the maximum priority user in O(1)
	{
		return data[0];
	}
	T findMin()//return the minimum priority user in O(1)
	{
		return data[data.size()];
	}
	int size()
	{
		return data.size();
	}
	bool empty()
	{
		return data.empty();
	}
	void print()
	{
		if (data.empty() == false)
		{
			cout << "User next in line to access the file : " << findMax() << endl;
		}
		cout << "Users waiting in line : ";
		if (data.size() != 0)
			cout << data.size() - 1 << endl;
		else
			cout << data.size() << endl;
	}
	friend ostream& operator << (ostream& out, PriorityQueue<T> const &f)
	{
		if (f.data.empty() == false)
		{
			out << "User next in line to access the file : " << f.data[0] << endl;
		}
		out << "Users waiting in line : ";
		if (f.data.size() != 0)
			out << f.data.size() - 1 << endl;
		else
			out << f.data.size() << endl;
		return out;
	}
	~PriorityQueue()
	{
		data.clear();
	}

	template <class T>
	friend class File;
};

template <class T>
class File
{
	int FileID; //every priority is associated with a File ID
	PriorityQueue<T> users;
	list<T> access;
public:
	File(int id)
	{
		FileID = id;
	}
	friend ostream& operator << (ostream& out, File<T> const &f)
	{
		out << "File ID : " << f.FileID << endl;
		if (f.access.empty() == false)
		{
			out << "Currently accessing file : " << endl;
			for (auto i = f.access.begin();i != f.access.end();i++)
			{
				out << *i << endl;
			}
		}
		out << f.users;
		return out;
	}
	bool operator == (File<T> f)
	{
		if (this->FileID == f.FileID)
			return true;
		return false;
	}
	void insert(T user)
	{
		/*
		first simply insert a new user to the waiting queue so that the priorities are cross checked
		with all the other users waiting in line, and then call the "giveNewAccess" function which
		will check who to give access to according to the priorities and operations
		*/
		if (inRange(user) == true)
		{
			users.insert(user);
			giveNewAccess();
		}
	}
	void giveNewAccess()
	{
		/*
		This func gives access to the users in waiting queue, if the maximum priority user is a reader
		and the access queue is also filled with readers than it will push that top waiting reader to the
		access queue to read but if the access queue consists of a writer than noone will get into the access queue
		*/
		if (users.empty() == false)//if the waiting queue is not empty
		{
			if (access.empty() == true && isReader(users.findMax()) == false)//if the top priority user is a writer
				access.push_front(users.extractMax());
			else //if its a reader on the top of waiting queue
			{
				for (int i = 0;i <= users.size();i++)//run the loop till you find a writer in waiting queue
				{
					if (isReader(users.findMax()) == true)//if the top priority user is a reader
					{
						if (access.empty() == false && isReader(access.front()) == true)//if access is not empty, and is filled with readers and the top waiting user is also a raeder
							access.push_front(users.extractMax());//push the top waiting reader to access
						else if (access.empty() == true)//if access is empty, and waiting top is a reader
							access.push_front(users.extractMax());//push that reader to access
						else
							break;
					}
					else
						break;
				}
			}
		}
	}
	bool empty()
	{
		return (users.empty() && access.empty());
	}
	void releaseCurrentUser(T user)
	{
		int count = 0;
		for (auto i = access.begin(); i != access.end();i++)
		{
			if (*i == user)
			{
				access.erase(i);//removes that element from access area
				count++;
				break;
			}
		}
		if (count == 0)
			cout << "The user didn't have access to the file, thus cannot be released." << endl;
		giveNewAccess();
	}
	~File()
	{
		access.clear();
	}
	template <class T>
	friend class HashTable;
};

template<typename T>
void Listprint(list<File<T>>& list)//helper function for printing STL lists
{
	for (auto it = list.cbegin(); it != list.cend(); it++) {
		cout << *it << "    ";
	}
}

template<class T>
class HashTable
{
	vector<list<File<T>>> files; //a vector which has a list on each index, and that list has a files data on every node
public:
	HashTable(int s = 101)
	{
		files.resize(s);
	}
	int hashFunc(int id)
	{
		return id % files.size();
	}
	bool searchFile(int fileID)
	{
		for (auto i = files[hashFunc(fileID)].begin(); i != files[hashFunc(fileID)].end(); i++)
		{
			if (*i == File<T>(fileID))
			{
				return true;
			}
		}
		return false;
	}
	void insertFile(int fileID)//pushes a file into the relevant index of hash table
	{
		if (fileID >= 5000 && fileID <= 99999)
		{
			if (searchFile(fileID) == false)//if that file doesnt already exist
				files[hashFunc(fileID)].push_front(File<T>(fileID));
			else
				cout << "File " << fileID << " already exists in the system." << endl;
		}
		else
			cout << "Invalid File ID. (Range: 5000 - 99999)" << endl;
	}
	void requestFile(T user, int fileID)
	{
		/*
		this func will push the user into the priority queue of the relevant file
		if the priority is 1, the user will get immediate access no matter if he is here to read or write
		if priority is 0, the user will be pushed to the normal waiting queue no matter he is here to read or write
		otherwise, the normal sequence would be: if you are here to write, you will be in the top of the queue no matter
		what your priority is, and readers will be waiting in sequence of highest to lowest priority
		*/
		int count = 0;
		for (auto i = files[hashFunc(fileID)].begin(); i != files[hashFunc(fileID)].end(); i++)
		{
			if (*i == File<T>(fileID))
			{
				(*i).insert(user);
				count++;
				break;
			}
		}
		if (count == 0)
			cout << "No file with ID " << fileID << " exists in the system." << endl;
	}
	void releaseaFile(T user, int fileID)
	{
		/*
		this func will release the user that currently is accessing the file and give access to the immediate next user in queue
		*/
		for (auto i = files[hashFunc(fileID)].begin(); i != files[hashFunc(fileID)].end(); i++)
		{
			if (*i == File<T>(fileID))//if that file exists
			{
				(*i).releaseCurrentUser(user);
				break;
			}
		}
	}
	void print()
	{
		for (int i = 0;i < files.size();i++)
		{
			cout << "(" << i << ") ";
			Listprint(files[i]);
			cout << endl;
		}
	}
	void loadData(string path)
	/*
	this func loads all the user access data to the hash table from a txt file
	*/
	{
		int fileid = 0;
		int userid = 0;
		int priority = 0;
		char oper = 'x';
		char comma = ',';
		fstream fin;
		fin.open(path);
		while (!fin.eof())
		{
			fin >> fileid;
			fin >> comma;
			fin >> userid;
			fin >> comma;
			fin >> priority;
			fin >> comma;
			fin >> oper;
			if (fin.eof())
				break;
			requestFile(userData(priority, userid, oper), fileid);
		}
		fin.close();
	}
	void loadFiles(string path)
	/*
	this func loads all the file ids to the hash table from a txt file
	*/
	{
		int fileid = 0;
		fstream fin;
		fin.open(path);
		while (!fin.eof())
		{
			fin >> fileid;
			insertFile(fileid);
		}
		fin.close();
	}
	void deleteAfile(int fileid)
	{
		int count = 0;
		for (auto i = files[hashFunc(fileid)].begin(); i != files[hashFunc(fileid)].end(); i++)
		{
			if (*i == File<T>(fileid))
			{
				count++;
				if ((*i).empty() == true)
				{
					files[hashFunc(fileid)].erase(i);
					count++;
					break;
				}
			}
		}
		if (count == 0)
			cout << "File " << fileid << " does not exist in the system." << endl;
		else if (count == 1)
			cout << "A user is currently accessing this file, it cannot be deleted yet." << endl;
	}
	~HashTable()
	{
		for (int i = 0;i < files.size();i++)//clears all the linked lists
		{
			files[i].clear();
		}
		files.clear();//clears the vector
	}
};

void menu(HashTable<userData> h)
{
top:
	system("cls");
	cout << "----------------MENU----------------" << endl;
	int choice = 0;
	string path = "";
	int fileid = 0,prior = 0,userid = 0;
	char oper = 'x', c = 'x';
	cout << "Enter\n1 to LOAD FILES\n2 to LOAD USERS\n3 to Insert a File\n4 to Print the Hash Table\n5 to Delete a File\n6 to request access for a file\n7 to Release access to a file\n8 to exit : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		cout << "----------------LOAD FILES TO HASH TABLE----------------" << endl;
		cout << "Enter path to file : ";
		cin >> path;
		h.loadFiles(path);
		cout << "Enter 'x' to exit, 'm' to go back to main menu : ";
		cin >> c;
		if (c == 'x')
			break;
		else if (c == 'm')
			goto top;
		break;
	case 2:
		system("cls");
		cout << "----------------LOAD USERS TO FILES IN HASH TABLE----------------" << endl;
		cout << "Enter path to file : ";
		cin >> path;
		h.loadData(path);
		cout << "Enter 'x' to exit, 'm' to go back to main menu : ";
		cin >> c;
		if (c == 'x')
			break;
		else if (c == 'm')
			goto top;
		break;
	case 3:
		system("cls");
		cout << "----------------INSERT A FILE----------------" << endl;
		cout << "Enter a file ID : ";
		cin >> fileid;
		h.insertFile(fileid);
		cout << "Enter 'x' to exit, 'm' to go back to main menu : ";
		cin >> c;
		if (c == 'x')
			break;
		else if (c == 'm')
			goto top;
		break;
	case 4:
		system("cls");
		cout << "----------------PRINT THE HASH TABLE----------------" << endl;
		h.print();
		cout << "Enter 'x' to exit, 'm' to go back to main menu : ";
		cin >> c;
		if (c == 'x')
			break;
		else if (c == 'm')
			goto top;
		break;
	case 5:
		system("cls");
		cout << "----------------DELETE A FILE----------------" << endl;
		cout << "Enter the ID of the file you want to delete : ";
		cin >> fileid;
		h.deleteAfile(fileid);
		cout << "Enter 'x' to exit, 'm' to go back to main menu : ";
		cin >> c;
		if (c == 'x')
			break;
		else if (c == 'm')
			goto top;
		break;
	case 6:
		system("cls");
		cout << "----------------REQUEST ACCESS TO A FILE----------------" << endl;
		cout << "Enter user details below." << endl;
		cout << "User Priority (reserved ints: 1 highest, 0 lowest) : ";
		cin >> prior;
		cout << "User ID : ";
		cin >> userid;
		cout << "User Operation : ";
		cin >> oper;
		cout << "ID of file to access : ";
		cin >> fileid;
		h.requestFile(userData(prior, userid, oper), fileid);
		cout << "Enter 'x' to exit, 'm' to go back to main menu : ";
		cin >> c;
		if (c == 'x')
			break;
		else if (c == 'm')
			goto top;
		break;
	case 7:
		system("cls");
		cout << "----------------RELEASE ACCESS TO A FILE----------------" << endl;
		cout << "Enter user details below." << endl;
		cout << "User Priority (reserved ints: 1 highest, 0 lowest) : ";
		cin >> prior;
		cout << "User ID : ";
		cin >> userid;
		cout << "User Operation : ";
		cin >> oper;
		cout << "Enter the ID of file to release its access : ";
		cin >> fileid;
		h.releaseaFile(userData(prior, userid, oper), fileid);
		cout << "Enter 'x' to exit, 'm' to go back to main menu : ";
		cin >> c;
		if (c == 'x')
			break;
		else if (c == 'm')
			goto top;
		break;
	case 8:
		break;
	default:
		goto top;
	}
}

int main()
{
	HashTable<userData>  h;
	menu(h);
	return 0;
}