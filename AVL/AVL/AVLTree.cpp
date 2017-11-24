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

void AVLTree::searchShit(string key, Node* node,string constrain) {
	if (constrain == "title") {
		if (node != NULL && key == node->title) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "surname") {
		if (node != NULL && key == node->surname) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "givenName") {
		if (node != NULL && key == node->givenName) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}else if (constrain == "gender") {
		if (node != NULL && key == node->gender) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}else if (constrain == "birthday") {
		if (node != NULL && key == node->dateOfBirth) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}else if (constrain == "address") {
		if (node != NULL && key == node->address) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}else if (constrain == "city") {
		if (node != NULL && key == node->city) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}else if (constrain == "stateFull") {
		if (node != NULL && key == node->stateFull) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}else if (constrain == "zipCode") {
		if (node != NULL && key == node->title) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}else if (constrain == "countryFull") {
		if (node != NULL && key == node->Country) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "telephoneCountryCode") {
		if (node != NULL && key == node->Country) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "telephone") {
		if (node != NULL && key == node->Country) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "countryFull") {
		if (node != NULL && key == node->Country) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "countryFull") {
		if (node != NULL && key == node->Country) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "countryFull") {
		if (node != NULL && key == node->Country) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "countryFull") {
		if (node != NULL && key == node->Country) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
	else if (constrain == "countryFull") {
		if (node != NULL && key == node->Country) {
			searchShit(key, node->left, constrain);
			addTo1d(node);
			searchShit(key, node->right, constrain);
		}
	}
}

void AVLTree::addTo1d(Node* node) {
	if (fucking1DArray == NULL) {
		fucking1DArray[0] = node;
	}
	else {
		int rows = sizeof(fucking1DArray) / sizeof(fucking1DArray[0]);
		fucking1DArray[rows + 1] = node;
	}
}
Node** AVLTree::get1dArray() {
	return fucking1DArray;
}

void AVLTree::del1dArray() {
	delete[]fucking1DArray;
}



void AVLTree::insert(Node* node, string* data) {
	string key = data[1] + data[2];
	root=root->insert(node,data,key);
}


Node* AVLTree::search(string key1,string key2) {
	return root->search(key1, key2,root);
}








