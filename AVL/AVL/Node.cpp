#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string* data) {
	data = this->data;
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
Node* Node::minValueNode(Node* node)
{
	Node* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

Node* Node::deleteNode(Node* node)
{
		if ((node->left == NULL) || (node->right == NULL))
		{
			Node *temp = node->left ? node->left :
				node->right;

			// No child case
			if (temp == NULL)
			{
				temp = node;
				node = NULL;
			}
			else // One child case
				node = temp;
			free(temp);
		}
		else
		{
			Node* temp = minValueNode(node->right);
			node->data = temp->data;
			node->key = temp->key;
			node->height = temp->height;
			string* data;
			deleteNode(temp);
		}
	
	if (node == NULL)
		return node;
	node->height = 1 + max(getHeight(node->left->left),getHeight(node->left->right));
	int balance = getBalance(node);
	if (balance > 1 && getBalance(node->left) >= 0)
		return rightRotate(node);
	if (balance > 1 && getBalance(node->left) < 0)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && getBalance(node->right) <= 0)
		return leftRotate(node);
	if (balance < -1 && getBalance(node->right) > 0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
return node;
}


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
		/*if (key2 == node->phoneNumber) {
			return node;
		}
		else
		{*/
			return node;
		//}
	}

}








