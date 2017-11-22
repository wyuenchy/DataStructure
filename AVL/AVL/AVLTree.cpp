#include "AVLTree.h"
#include "Node.h"
#include <iostream>
using namespace std;


AVLTree::AVLTree() {
	root = NULL;
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

void AVLTree::insert(Node* node, int key) {
	root=root->insert(node, key);
}


void AVLTree::deleteN(Node* node, int key) {
	root = root->deleteN(node, key);
}


Node* AVLTree::search(int key) {
	if (root==NULL) {
		cout << "The tree is empty\t";
	}
	else {
		return root->search(key);
	}
}






