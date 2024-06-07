#include <iostream>
using namespace std;

class PatientRecord
{
	int ID;
	string name;
	string admission_date;
	string diagnosis;
	bool status; //true for admitted, false for discharged
public:
	friend class HospitalData;
	PatientRecord(int id,string nam,string date,string diagnos,bool stats):ID(id),name(nam),admission_date(date),diagnosis(diagnos),status(stats){}
	PatientRecord()
	{
		this->ID = 0;
		this->name = "";
		this->admission_date = "";
		this->diagnosis = "";
		this->status = false;
	}
	PatientRecord(const PatientRecord& p)
	{
		this->ID = p.ID;
		this->name = p.name;
		this->admission_date = p.admission_date;
		this->diagnosis = p.diagnosis;
		this->status = p.status;
	}
	PatientRecord operator = (const PatientRecord& p)
	{
		if (&p)
		{
			this->ID = p.ID;
			this->name = p.name;
			this->admission_date = p.admission_date;
			this->diagnosis = p.diagnosis;
			this->status = p.status;
		}
		return *this;
	}
	void print()
	{
		if (this)
		{
			cout << "ID : " << this->ID << endl;
			cout << "Name : " << this->name << endl;
			cout << "Admission Date : " << this->admission_date << endl;
			cout << "Diagnosis : " << this->diagnosis << endl;
			cout << "Status : ";
			if (status == true)
				cout << "Admitted" << endl << endl;
			else
				cout << "Discharged" << endl << endl;
		}
	}
	~PatientRecord()
	{
		this->ID = 0;
		this->name = "";
		this->admission_date = "";
		this->diagnosis = "";
		this->status = false;
	}
};

class Node
{
public:
	PatientRecord data;
	Node* right;
	Node* left;

	friend class HospitalData;
	Node(PatientRecord p):right(nullptr),left(nullptr),data(p){}
};

class HospitalData
{
	Node* root;
	int size;
public:
	HospitalData(int s = 0):root(nullptr),size(s){}
	void insert(PatientRecord p)//inserts a new patient to the root and moves the rest nodes accordingly beneath
	{
		PatientRecord temp;
		if (root != nullptr)
		{
			temp = root->data;
			root->data = p;
			Node* original = root;
			while (root != nullptr)
			{
				if (temp.ID > root->data.ID)
				{
					if (root->right != nullptr)
						root = root->right;
					else
					{
						root->right = new Node(temp);
						size++;
						break;
					}
				}
				else if (temp.ID < root->data.ID)
				{
					if (root->left != nullptr)
						root = root->left;
					else
					{
						root->left = new Node(temp);
						size++;
						break;
					}
				}
			}
			root = original;
		}
		else
		{
			root = new Node(p);
			size++;
		}
	}

	void print() const
	{
		print(root);
	}

	void print(Node* t) const
	{
		if (t)
		{
			print(t->left);
			t->data.print();
			print(t->right);
		}
	}

	void printA(Node* t)//wrapper to print all admitted patients starting from the newest to oldest
	{
		if (t)
		{
			if (t->data.status == true)
				t->data.print();
			printA(t->left);
			printA(t->right);
		}
	}

	void printAdmitted()
	{
		printA(root);
	}

	int height(Node* t)
	{
		if (t == nullptr)
			return 0;
		else
		{
			int Leftheight = height(t->left);
			int Rightheight = height(t->right);
			if (Leftheight > Rightheight)
				return (Leftheight + 1);
			else return (Rightheight + 1);
		}
	}

	void rem(Node* t, int id)
	{
		if (t)
		{
			
		}
	}

	void remove(int id)
	{
		rem(root, id);
	}

	void rightRotate(Node*& x)
	{
		Node* orphan = x->left->right;
		Node* y = x->left;
		y->right = x;
		x->left = orphan;
		x = y;
	}
	void leftRotate(Node*& x)
	{
		Node* orphan = x->right->left;
		Node* y = x->right;
		y->left = x;
		x->right = orphan;
		x = y;
	}

	void moveToLevel(Node* t, int rotations)
	{
		leftRotate(t);
	}

	void search(Node* t, int id, Node*& ptr)
	{
		if (t)
		{
			search(t->left,id,ptr);
			search(t->right,id,ptr);
			if (t->data.ID == id)
				ptr = t;
		}
	}

	Node* search(int id, int k)
	{
		Node* t = nullptr;
		search(root, id, t);
		if (!t)
			cout << "Patient with ID : " << id << " not found." << endl;
		else
		{
			int h = height(t);
			if (h != k)
			{
				cout << "Node not found on given level "<< k << " but on level " << h << endl;
				cout << "Now moving the node to level " << k << endl;
				moveToLevel(t, k - h);
			}
			else
				cout << "Node found on level " << k << endl;
		}
		return t;
	}

	void clear(Node* &t)//wrapper for clear()
	{
		if (t)
		{
			clear(t->left);
			clear(t->right);
			delete t;
			t = nullptr;
		}
	}

	void clear()
	{
		clear(root);
	}

	~HospitalData()
	{
		clear();
		delete root;
		root = nullptr;
	}
};

int main()
{
	HospitalData h(10);
	h.insert(PatientRecord(6, "uvw", "12-12-12", "cancer", false));
	h.insert(PatientRecord(2, "rst", "12-12-12", "cancer", true));
	h.insert(PatientRecord(7, "opq", "12-12-12", "cancer", true));
	h.insert(PatientRecord(5, "lmn", "12-12-12", "cancer", false));
	h.insert(PatientRecord(3, "xyz", "12-12-12", "cancer", true));
	h.insert(PatientRecord(4, "abc", "12-12-12", "cancer", false));
	h.insert(PatientRecord(10, "abc", "12-12-12", "cancer", false));
	h.insert(PatientRecord(8, "abc", "12-12-12", "cancer", false));
	h.insert(PatientRecord(9, "abc", "12-12-12", "cancer", false));
	h.insert(PatientRecord(1, "abc", "12-12-12", "cancer", false));
	h.print();
	Node* a = h.search(3, 5);
	a->data.print();
	Node* b = h.search(3, 5);
	b->data.print();
}