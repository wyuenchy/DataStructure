#include "AVLTree.h"
#include "Node.h"
#include <iostream>
using namespace std;


AVLTree::AVLTree() {
	root = NULL;
}

int AVLTree::max(int left, int right) {
	return (left > right) ? left : right;
}

int AVLTree::height(Node* node) {
	if (node==NULL) {
		return 0;
	}

	return node->height;
}

Node* AVLTree::rightRotate(Node* y) {
	Node* x = y->left;
	Node* T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node* AVLTree::leftRotate(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	//  Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

Node* AVLTree::DoubleRRotate(Node* node) {
	node->right = leftRotate(node->right);
	return rightRotate(node);
}

Node* AVLTree::DoubleLRotate(Node* node) {
	node->right = rightRotate(node->left);
	return leftRotate(node);
}

int AVLTree::getBalance(Node* node) {
	if (node==NULL) {
		return 0;
	}
	return height(node->left) - height(node->right);
}


Node* AVLTree::insert(Node* node, int key) {
	//if the tree is empty
	if (node==NULL) {
		return (new Node(key));
	}
	
	

	//check the key is smaller
	if (key < node->key) {
		node->left = insert(node->left, key);		//insert to the node left
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}

	//update height
	node->height = max(height(node->left), height(node->right)) + 1;
	int balance = getBalance(node);

	//////////////////////////////unbalanced

	//right zig-zig
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	
	//left zig-zig
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Left Right zig zag
	if (balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left zig zag
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;

}


void AVLTree::preOrder(Node* node) {
	if (node != NULL) {
		cout << node->key << "\t";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void AVLTree::inOrder(Node* node) {
	if (node != NULL) {
		inOrder(node->left);
		cout << node->key << "\t";
		inOrder(node->right);
	}
}

