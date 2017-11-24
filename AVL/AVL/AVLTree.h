

#ifndef  AVLTREE_H
#define	AVLTREE_H
#include "Node.h"

class AVLTree{

public:
	AVLTree();
	Node* root;
<<<<<<< HEAD
	Node** fucking1DArray;
	void preOrder(Node* node);
	void inOrder(Node* node);
	void insert(Node* node, string* data);
	void searchShit(string key, Node* node,string constrain);
	void addTo1d(Node* node);
	Node** get1dArray();
	void del1dArray();
	Node* search(string key1,string key2);
=======
	int height(Node* node);
	int max(int left, int right);
	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);
	Node* DoubleRRotate(Node* y);
	Node* DoubleLRotate(Node* x);
	int getBalance(Node* node);
	Node* insert(Node* node, int key);
	void preOrder(Node* node);
	void inOrder(Node* node);
>>>>>>> 7305c7379c06ee3e5551e99221ae34d8cb22a131

	Node* minNode(Node* node);
	Node* deleteN(Node* node, int key);
};


#endif 
