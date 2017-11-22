#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
public:

	int key;
	int height;
	Node* left;
	Node* right;

	//constructor
	Node(int d);


	
	int getHeight(Node* node);
	int max(int left, int right);
	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);
	Node* DoubleRRotate(Node* y);
	Node* DoubleLRotate(Node* x);
	int getBalance(Node* node);
	Node* insert(Node* node, int key);
	
	Node* minNode(Node* node);
	Node* deleteN(Node* node, int key);
	Node* search(int key);
};


#endif