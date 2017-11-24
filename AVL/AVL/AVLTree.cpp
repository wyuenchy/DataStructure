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
/*
void AVLTree::searchShit(string key, Node* node, int i) {
	if (node != NULL && key==node->data[i]) {
		searchShit(key, node->left, i);
		addTo2d(node);
		searchShit(key, node->right, i);
	}
}
void AVLTree::addTo2d(Node* node) {
	if (fucking2DArray == NULL) {
		fucking2DArray[0][0] = node->data[0];
		fucking2DArray[0][1] = node->data[1];
		fucking2DArray[0][2] = node->data[2];
		fucking2DArray[0][3] = node->data[3];
		fucking2DArray[0][4] = node->data[4];
		fucking2DArray[0][5] = node->data[5];
		fucking2DArray[0][6] = node->data[6];
		fucking2DArray[0][7] = node->data[7];
		fucking2DArray[0][8] = node->data[8];
		fucking2DArray[0][9] = node->data[9];
		fucking2DArray[0][10] = node->data[10];
		fucking2DArray[0][11] = node->data[11];
		fucking2DArray[0][12] = node->data[12];
		fucking2DArray[0][13] = node->data[13];
		fucking2DArray[0][14] = node->data[14];
	}
	else {
		int rows = sizeof(fucking2DArray) / sizeof(fucking2DArray[0]);
		fucking2DArray[rows + 1][0] = node->data[0];
		fucking2DArray[rows + 1][1] = node->data[1];
		fucking2DArray[rows + 1][2] = node->data[2];
		fucking2DArray[rows + 1][3] = node->data[3];
		fucking2DArray[rows + 1][4] = node->data[4];
		fucking2DArray[rows + 1][5] = node->data[5];
		fucking2DArray[rows + 1][6] = node->data[6];
		fucking2DArray[rows + 1][7] = node->data[7];
		fucking2DArray[rows + 1][8] = node->data[8];
		fucking2DArray[rows + 1][9] = node->data[9];
		fucking2DArray[rows + 1][10] = node->data[10];
		fucking2DArray[rows + 1][11] = node->data[11];
		fucking2DArray[rows + 1][12] = node->data[12];
		fucking2DArray[rows + 1][13] = node->data[13];
		fucking2DArray[rows + 1][14] = node->data[14];
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
*/


void AVLTree::insert(Node* node, string* data) {
	string key = data[1] + data[2];
	root=root->insert(node,data,key);
}


Node* AVLTree::search(string key1,string key2) {
	return root->search(key1, key2,root);
}








