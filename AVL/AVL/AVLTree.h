

#ifndef  AVLTREE_H
#define	AVLTREE_H
#include "Node.h"

class AVLTree{

public:
	AVLTree();
	Node* root;
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
};


#endif 
