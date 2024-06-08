#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

// Define the structure of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node in the binary tree
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to search for a specific value in the binary tree
bool searchNode(Node* root, int value) {
    if (root == NULL) {
        return false;
    } else if (root->data == value) {
        return true;
    } else if (value <= root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// Function to print the binary tree in-order
void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Define the number of nodes in the binary tree
    const int numNodes = 30;

    // Declare the root node of the binary tree
    Node* root = NULL;

    // Populate the binary tree with random integer values
    #pragma omp parallel for
    for (int i = 0; i < numNodes; i++) {
        int value = rand() % 100;
        #pragma omp critical
        {
            root = insertNode(root, value);
        }
    }

    // Print the binary tree
    cout << "Binary tree:" << endl;
    printTree(root);
    cout << endl;

    // Search for a specific value in the binary tree
    int searchValue = 42;
    bool found = searchNode(root, searchValue);
    if (found) {
        cout << "The value " << searchValue << " was found in the binary tree." << endl;
    } else {
        cout << "The value " << searchValue << " was not found in the binary tree." << endl;
    }

    return 0;
}