

#ifndef  AVLTREE_H
#define	AVLTREE_H
#include "Node.h"

class AVLTree{

public:
	AVLTree();
	Node* root;
	
	void preOrder(Node* node);
	void inOrder(Node* node);
	void insert(Node* node, string* data);

	//void deleteN(Node* node, int key);
	Node* search(string key1,string key2);
	//void display(Node* node);
};


#endif 
