#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string* data) {

	title = data[0];
	surname = data[1];
	givenName = data[2];
	gender = data[3];
	dateOfBirth = data[4];
	address = data[5];
	city = data[6];
	stateFull = data[7];
	zipCode = data[8];
	Country = data[9];
	teleCountryCode = data[10];
	phoneNumber = data[11];
	emailAddress = data[12];
	occupation = data[13];
	company = data[14];


	
	key = data[1] + data[2];
	height = 1;
	left = right = NULL;
	
}


int Node::max(int left, int right) {
	return (left > right) ? left : right;
}

int Node::getHeight(Node* node) {
	if (node == NULL) {
		return 0;
	}

	return node->height;
}

Node* Node::rightRotate(Node* y) {
	Node* x = y->left;
	Node* T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	return x;
}

Node* Node::leftRotate(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	//  Update heights
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}



int Node::getBalance(Node* node) {
	if (node == NULL) {
		return 0;
	}
	return getHeight(node->left) - getHeight(node->right);
}


Node* Node::insert(Node* node, string* data,string key) {


	//if the tree is empty
	if (node == NULL) {
		return (new Node(data));
	}


	//check the key is smaller
	if (key.compare(node->key)<0) {
		node->left = insert(node->left, data,key);		//insert to the node left
	}
	else if (key.compare(node->key)>0) {
		node->right = insert(node->right, data,key);
	}
	else {
		//node->list.insertNode()
	}

	//update height
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	int balance = getBalance(node);

	//////////////////////////////unbalanced

	//right zig-zig
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	//left zig-zig
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Left Right zig zag
	if (balance > 1 && key > node->left->key) {
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

/*
Node* Node::minNode(Node* node) {
	while (node->left != NULL) {
		node = node->left;
	}
	return node;
}


Node* Node::deleteN(Node* node, int key) {
	//empty tree
	if (node == NULL)
		return node;

	if (key < node->key) {
		node->left = deleteN(node->left, key);
	}
	else if (key> node->key) {
		node->right = deleteN(node->right, key);
	}
	//same as the node key
	else {
		if ((node->left == NULL) || (node->right == NULL)) {
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

	if (node == NULL)
		return node;

	//update height
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	int balance = getBalance(node);

	//////////////////////////////unbalanced

	//right zig-zig
	if (balance < -1 && getBalance(node->right) <= 0)
		return leftRotate(node);

	//left zig-zig
	if (balance > 1 && getBalance(node->left) >= 0)
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
*/


Node* Node::search(string key1,string key2,Node* node) {

	if (node==NULL) 
		return NULL;
	
	
	if (key1<node->key) {
		return search(key1, key2,node->left);
	}
	else if(key1>node->key) {
		return search(key1, key2,node->right);
	}
	else {
		return node;
	}

}








