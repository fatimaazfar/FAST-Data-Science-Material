#include <iostream>
using namespace std;

class node
{
	int data;
	node* right;
	node* left;
public:
	friend class BST;
	node(int d = 0) :data(d), right(0), left(0){}
	node(int d, node* r, node* l) :data(d), right(r), left(l){}
};

class BST
{
	node* root;
public:
	BST():root(0){}
	void insert(int key)
	{
		if (root == nullptr)
		{
			root = new node(key);
		}
		else
		{
			node* temp = root;
			insert(root, key);
			root = temp;
		}
	}
	void insert(node* &top, int key)//wrap around function for insert
	{
		if (top != nullptr)
		{
			if (key > top->data)
				return insert(top->right, key);
			else
				return insert(top->left, key);
		}
		else
		{
			top = new node(key);
		}
	}
	void print()
	{
		print(root);
	}
	void print(node* t)
	{
		if (t)
		{
			print(t->left);
			cout << t->data << " ";
			print(t->right);
		}
	}
	void clear()
	{
		clear(root);
	}
	void clear(node* t)
	{
		if (t)
		{
			clear(t->left);
			if (t->right == nullptr && t->left == nullptr)
				delete t;
			else
			{
				clear(t->right);
				if (t->left == nullptr)
					delete t;
			}
		}
	}
	~BST()
	{
		clear();
		delete root;
		root = nullptr;
	}
};

int main()
{
	BST tree;
	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.print();
}