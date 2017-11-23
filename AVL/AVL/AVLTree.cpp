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


void AVLTree::insert(Node* node, string* data) {
	string key = data[1] + data[2];
	root=root->insert(node,data,key);
}


/*
void AVLTree::deleteN(Node* node, int key) {
	root = root->deleteN(node, key);
}
*/

Node* AVLTree::search(string key1,string key2) {
	return root->search(key1, key2,root);
}








