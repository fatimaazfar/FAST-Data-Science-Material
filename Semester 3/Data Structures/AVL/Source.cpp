#include <iostream>
using namespace std;

template <typename k, typename v>
class TNode
{
public:
	k key;
	v value;
	int height;
	TNode<k, v>* leftChild;
	TNode<k, v>* rightChild;
	TNode(k keyy, v valuee) :key(keyy), value(valuee), leftChild(nullptr), rightChild(nullptr), height(-1) {}
	template<class k, class v>
	friend class BST;
};

template <typename k, typename v>
class BST
{
public:
	TNode<k, v>* root;
	BST() :root(nullptr) {}

	void insertRec(k const  key, v const value)
	{
		ins(key, value, root);
		root->height++;
	}

	void ins(k const  key, v const value, TNode<k, v>*& root1)
	{
		if (!root1)
		{
			root1 = new TNode<k, v>(key, value);
			root1->height++;
		}
		else
		{
			if (key > root1->key)
				ins(key, value, root1->rightChild);
			else if (key < root1->key)
				ins(key, value, root1->leftChild);
		}
	}

	void inorderPrintKeysRec() const
	{
		inorder(root);
	}

	void inorder(TNode<k, v>* t) const
	{
		if (t)
		{
			inorder(t->leftChild);
			cout << t->key << " ";
			inorder(t->rightChild);
		}
	}

	void insert(k const  key, v const value)
	{
		TNode<k, v>* temp = root;
		if (root == nullptr)
		{
			root = new TNode<k, v>(key, value);
			temp = root;
		}
		else
		{
			while (root != nullptr)
			{
				if (key > root->key)
				{
					if (root->rightChild != nullptr)
					{
						root = root->rightChild;
					}
					else
					{
						root->rightChild = new TNode<k, v>(key, value);
						break;
					}
				}
				else if (key < root->key)
				{
					if (root->leftChild != nullptr)
					{
						root = root->leftChild;
					}
					else
					{
						root->leftChild = new TNode<k, v>(key, value);
						break;
					}
				}
			}
		}
		root = temp;
	}

	void printAllAncestors(k const  key) const
	{
		TNode<k, v>* root1 = root;
		while (root1 != nullptr)
		{
			if (root1->key != key)
			{
				cout << " " << root1->key << " ";
				if (key > root1->key)
					root1 = root1->rightChild;
				else
					root1 = root1->leftChild;
			}
			else
				break;
		}
	}

	int length()
	{
		return length(root);
	}

	int length(TNode<k, v>* temp)
	{
		if (temp == nullptr)
			return 0;
		else
			return (length(temp->leftChild) + length(temp->rightChild) + 1);
	}

	k getPredecessor(TNode<k, v>* node)
	{
		k keyyy;
		if (node != nullptr)
		{
			keyyy = node->key;
			if (node->leftChild != nullptr)
			{
				if (node->rightChild != nullptr)
				{
					TNode<k, v>* temp = node->leftChild;
					while (temp->rightChild != nullptr)
					{
						keyyy = temp->key;
						temp = temp->rightChild;
					}
				}
				else
				{
					keyyy = node->leftChild->key;
				}
			}
		}
		return keyyy;
	}

	void deleteNode(TNode <k, v>*& node) {

		TNode <k, v>* temp = node;
		if (node->leftChild == NULL) {
			node = node->rightChild;
			delete temp;
		}
		else if (node->rightChild == NULL) {
			node = node->leftChild;
			delete temp;
		}
		else {
			k d = getPredecessor(node->leftChild);
			node->key = d;
			deleteR(d, node->leftChild);
		}
	}

	void deleteR(k d)
	{
		deleteR(d, root);
	}


	void deleteR(k d, TNode<k, v>*& node)
	{
		if (node)
		{
			if (d > node->key)
				deleteR(d, node->rightChild);
			else if (d < node->key)
				deleteR(d, node->leftChild);
			else
				deleteNode(node);
		}
	}

	v* search(k key)
	{
		return search(root, key);
	}
	v* search(TNode<k, v>* ptr, k key)
	{
		if (ptr == nullptr)
			return nullptr;
		else if (ptr->key == key)
			return &ptr->value;
		else if (ptr->key < key)
			return search(ptr->rightChild, key);
		else
			return search(ptr->leftChild, key);
	}

};

template <typename k, typename v>
class AVLNode : public BST<k, v>
{
public:
	AVLNode() {}
	void insertRec(k const  key, v const value)
	{
		BST<k,v>::root->height++;
		BST<k, v>::insertRec(key, value);
		balance(BST<k, v>::root);
	}
	void rightRotate(AVLNode*& x)
	{
		AVLNode* orphan = x->leftChild->rightChild;
		AVLNode* y = x->leftChild;
		y1->rightChild = x;
		x->leftChild = orphan;
		x->height = height(x);
		y->height = height(y);
		x = y;
	}
	void leftRotate(AVLNode*& x)
	{
		AVLNode* orphan = x->righttChild->leftChild;
		AVLNode* y = x->rightChild;
		y1->leftChild = x;
		x->rightChild = orphan;
		x->height = height(x);
		y->height = height(y);
		x = y;
	}

	void doubleLeftRightRotation(AVLNode*& X)
	{
		leftRotate(X->leftChild);
		rightRotate(X);
	}

	void doubleRightLeftRotation(AVLNode*& X)
	{
		rightRotate(X->rightChild);
		leftRotate(X);
	}

	void balance(AVLNode*& t)
	{
		if (t == nullptr)
			return;
		if (height(t->leftChild) - height(t->rightChild) > 1)
			if (height(t->leftChild->leftChild) >= height(t->leftChild->rightChild))
				rightRotate(t);
			else
				doubleLeftRightRotation(t);
		else if (height(t->rightChild) - height(t->leftChild) > 1)
			if (height(t->rightChild->rightChild) >= height(t->rightChild->leftChild))
				leftRotate(t);
			else
				doubleRightLeftRotation(t);
		t->height = max(height(t->leftChild), height(t->rightChild)) + 1;
	}

	void inorderPrintKeys()
	{
		BST<k, v>::inorderPrintKeysRec();
	}

	int height()
	{
		return BST<k,v>::root->height;
	}

	v* search(k key)
	{
		return BST<k, v>::search(key);
	}

	void deleteR(k d)
	{
		BST<k, v>::deleteR(d);
	}

};

int main()
{
	AVLNode<int, int> tree;


	for (int i = 1; i <= 100; i++)
		tree.insert(i, i);

	for (int i = -1; i >= -100; i--)
		tree.insert(i, i);

	for (int i = 150; i > 100; i--)
		tree.insert(i, i);

	for (int i = -150; i < -100; i++)
		tree.insert(i, i);
	tree.inorderPrintKeys();
	cout << endl << endl;

	for (int i = 150; i > 100; i--)
		tree.deleteR(i);

	tree.inorderPrintKeys();
	cout << endl << endl;
	cout << "Tree Height: " << tree.height() << endl;

	int* val = tree.search(-100);

	if (val != nullptr)
	{
		cout << "Key= -100 found" << endl;
	}
	val = tree.search(-151);
	if (val == nullptr)
	{
		cout << "Key= -151 not found" << endl;
	}
	system("pause");
}

//int main()
//{
//	BST<int, int> tree; //the key and value both are of type int
//
//	tree.insert(500, 500);
//	tree.insertRec(1000, 1000);
//	tree.insert(1, 1);
//	tree.insert(600, 600);
//	tree.insertRec(700, 700);
//	tree.insert(10, 10);
//	tree.insert(30, 30);
//	tree.insertRec(9000, 9000);
//	tree.insert(50000, 50000);
//	tree.insertRec(20, 20);
//
//	cout << endl << endl << "Printing tree: ";
//	tree.inorderPrintKeysRec();
//
//	cout << endl << endl<< "Tree Length: " << tree.length() << endl << endl;
//
//	tree.deleteNode(tree.root);
//
//	cout << endl << endl << "Printing tree after deletion: ";
//	tree.inorderPrintKeysRec();
//
//	cout << endl << endl<< "Tree Length: " << tree.length() << endl << endl;
//
//	system("pause");
//	return 0;
//}