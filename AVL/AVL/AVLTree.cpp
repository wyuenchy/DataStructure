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

void AVLTree::searchShit(string key, Node* node, int i) {
	if (node != NULL) {
		searchShit(key, node->left, i);
		addTo2d(node);
		searchShit(key, node->right, i);
	}
}
void AVLTree::addTo2d(Node* node) {
	if (fucking2DArray == NULL) {
		fucking2DArray[0][0] = node->title;
		fucking2DArray[0][1] = node->surname;
		fucking2DArray[0][2] = node->givenName;
		fucking2DArray[0][3] = node->gender;
		fucking2DArray[0][4] = node->dateOfBirth;
		fucking2DArray[0][5] = node->address; 
		fucking2DArray[0][6] = node->city;
		fucking2DArray[0][7] = node->stateFull; 
		fucking2DArray[0][8] = node->zipCode; 
		fucking2DArray[0][9] = node->Country; 
		fucking2DArray[0][10] = node->teleCountryCode;
		fucking2DArray[0][11] = node->phoneNumber;
		fucking2DArray[0][12] = node->emailAddress;
		fucking2DArray[0][13] = node->occupation;
		fucking2DArray[0][14] = node->company;
	}
	else {
		int rows = sizeof(fucking2DArray) / sizeof(fucking2DArray[0]);
		fucking2DArray[rows + 1][0] = node->title;
		fucking2DArray[rows + 1][1] = node->surname;
		fucking2DArray[rows + 1][2] = node->givenName;
		fucking2DArray[rows + 1][3] = node->gender;
		fucking2DArray[rows + 1][4] = node->dateOfBirth;
		fucking2DArray[rows + 1][5] = node->address;
		fucking2DArray[rows + 1][6] = node->city;
		fucking2DArray[rows + 1][7] = node->stateFull;
		fucking2DArray[rows + 1][8] = node->zipCode;
		fucking2DArray[rows + 1][9] = node->Country;
		fucking2DArray[rows + 1][10] = node->teleCountryCode;
		fucking2DArray[rows + 1][11] = node->phoneNumber;
		fucking2DArray[rows + 1][12] = node->emailAddress;
		fucking2DArray[rows + 1][13] = node->occupation;
		fucking2DArray[rows + 1][14] = node->company;
	}
}
string** AVLTree::get2dArray() {
	return fucking2DArray;
}

void AVLTree::del2dArray() {
	int cols = sizeof(fucking2DArray[0]) / sizeof(fucking2DArray[0][0]);
	for (int i = 0; i < cols; i++) {
		delete[] fucking2DArray[i];
	}
	delete[]fucking2DArray;
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








