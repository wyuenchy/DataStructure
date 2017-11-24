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
<<<<<<< HEAD

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
=======
Node* AVLTree::minNode(Node* node) {
	while (node->left!=NULL) {
		node = node->left;
>>>>>>> 7305c7379c06ee3e5551e99221ae34d8cb22a131
	}
	return node;
}

<<<<<<< HEAD
void AVLTree::addTo1d(Node* node) {
	if (fucking1DArray == NULL) {
		fucking1DArray[0] = node;
=======
Node* AVLTree::deleteN(Node* node,int key) {
	//empty tree
	if (node == NULL)
		return node;

	if (key < node->key) {
		node->left = deleteN(node->left, key);
	}else if (key> node->key) {
		node->right = deleteN(node->right, key);
>>>>>>> 7305c7379c06ee3e5551e99221ae34d8cb22a131
	}
	//same as the node key
	else {
<<<<<<< HEAD
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

=======
		if ((node->left==NULL)||(node->right==NULL)) {
			Node* temp = node->left ? node->left : node->right;

			//case 1:	no child
			if (temp == NULL) {
				temp = node;
				node = NULL;
			}
			//case 2:	one child
			else {
				*node = *temp;		//copy the content of 
				delete temp;
			}

		}
		else {
			//case 3:	two child
			Node* temp = minNode(node->right);		//find the min value of right sub tree

			node->key = temp->key;					//replace the node key with the min vlaue in right sub tree

			node->right = deleteN(node->right, temp->key);		//del the min value
		}

	}
>>>>>>> 7305c7379c06ee3e5551e99221ae34d8cb22a131

	if (node == NULL)
		return node;

	//update height
	node->height = max(height(node->left), height(node->right)) + 1;
	int balance = getBalance(node);

	//////////////////////////////unbalanced

	//right zig-zig
	if (balance < -1 && getBalance(node->right)<=0)
		return leftRotate(node);

	//left zig-zig
	if (balance > 1 && getBalance(node->left)>=0)
		return rightRotate(node);

	// Left Right zig zag
	if (balance > 1 && getBalance(node->left)<0) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left zig zag
	if (balance < -1 && getBalance(node->right)>0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;

}





