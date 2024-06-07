#include <iostream>
using namespace std;

class node
{
	int data;
	node* right;
	node* left;
public:
	friend class BST;
	node(int d = 0) :data(d), right(0), left(0) {}
	node(int d, node* r, node* l) :data(d), right(r), left(l) {}
};

class BST
{
	node* root;
	int length;
public:
	BST() :root(0),length(0) {}
	BST(BST& b)//copy constructor
	{
		deepcopy(this->root, b.root);
		this->length = b.length;
	}
	void deepcopy(node* &destiny, node* &source)
	{
		if (source == nullptr)
		{
			destiny = nullptr;
		}
		else
		{
			destiny = new node(source->data);
			deepcopy(destiny->left, source->left);
			deepcopy(destiny->right, source->right);
		}
	}
	BST operator = (BST& b)
	{
		deepcopy(this->root, b.root);
		this->length = b.length;
		return *this;
	}
	void isequal(node* root1, node* root2, int& size)
	{
		if (root1 != nullptr && root2 != nullptr)
		{
			if (root1->data == root2->data)
				size++;
			isequal(root1->left, root2->left, size);
			isequal(root1->right, root2->right, size);
		}
	}
	bool operator == (const BST& b)
	{
		int size = 0;
		if (this->root == nullptr || b.root == nullptr)
			return false;
		else if (this->length != b.length)
			return false;
		isequal(this->root, b.root,size);
		if (size == length)
			return true;
		return false;
	}
	void insert(int key)
	{
		if (root == nullptr)
		{
			root = new node(key);
			length++;
		}
		else
		{
			node* temp = root;
			insert(root, key);
			root = temp;
		}
	}
	void insert(node*& top, int key)//wrap around function for insert
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
			length++;
		}
	}
	void print()
	{
		cout << "Length : " << length << endl;
		print(root);
		cout << endl;
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
	int height(node* t)
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
	void printLevel(node* t, int level)//prints only the nodes of the level passed to it
	{
		if (t == nullptr)
			return;
		if (level == 1)//if the level is the top level then print directly
			cout << t->data << " ";
		else if (level > 1)//otherwise keep decreasing the level till its 1 and pass left and right
		{
			printLevel(t->left, level - 1);
			printLevel(t->right, level - 1);
		}
	}
	void levelOrderPrint()
	{
		cout << "Length : " << length << endl;
		int h = height(root);//calculate total height
		for (int i = h;i >= 0;i--)//print from the leaf level to the root level
			printLevel(root, i);
		cout << endl;
	}
	void leafcount(node* t, int& num)//counts only the nodes that have no child i.e leaves
	{
		if (t)
		{
			leafcount(t->left, num);
			if (t->right == nullptr && t->left == nullptr)
				num++;
			leafcount(t->right, num);
		}
	}
	int leavesNum()
	{
		int num = 0;
		leafcount(root,num);//wrapper for recursion
		return num;
	}
	void clear()
	{
		length = 0;
		clear(root);
	}
	void clear(node* &t)//deletes all nodes starting from the lowest to the highest
	{
		if (t)
		{
			clear(t->left);
			clear(t->right);
			delete t;
			t = nullptr;
		}
	}
	~BST()//destructor
	{
		clear();
	}
	void common_ansector(int k1, int k2)
	{
		ca(root, root, k1, k2);
	}
	void ca(node* t1,node* t2, int k, int k2)
	{
		if (t1 && t2)
		{
			if (t1->data != k && t2->data != k2 && t1->data == t2->data)
			{
				cout << t1->data << " ";
				return;
			}
			ca(t1->left, t2->left,k,k2);
			ca(t1->right, t2->right,k,k2);
		}
	}
};

int main()
{
	BST tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(4);
	tree.insert(8);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);
	tree.insert(9);
	tree.insert(6);
	tree.print();
	//tree.common_ansector(1,2);
	BST tree2;
	tree2.insert(1);
	tree2.insert(1);
	tree2.insert(1);
	tree2.insert(1);
	tree2.insert(1);
	tree2.insert(1);
	tree2.print();
	tree2 = tree; //tree and tree 2 become equal
	tree2.print();
	if (tree == tree2)
		cout << "Equal" << endl; //prints equal
	else
		cout << "Unequal" << endl;
	BST tree3;
	tree3.insert(5);
	tree3.insert(3);
	tree3.insert(4);//leaf
	tree3.insert(2);//leaf
	tree3.insert(7);
	tree3.insert(6);//leaf
	tree3.insert(8);//leaf
	cout << "Number of leaves : " << tree3.leavesNum() << endl;
	cout << "Level order printing tree 3 and tree2 : " << endl;
	tree3.levelOrderPrint();
	tree2.levelOrderPrint();
	system("pause");
}