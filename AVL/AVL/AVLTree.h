

#ifndef  AVLTREE_H
#define	AVLTREE_H
#include "Node.h"

class AVLTree{

public:
	AVLTree();
	Node* root;
	
	void preOrder(Node* node);
	void inOrder(Node* node);
	void insert(Node* node, int key);
	void deleteN(Node* node, int key);
	Node* search(int key);
};


#endif 
