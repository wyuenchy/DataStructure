

#ifndef  AVLTREE_H
#define	AVLTREE_H
#include "Node.h"

class AVLTree{

public:
	AVLTree();
	Node* root;
	Node** fucking1DArray;
	void preOrder(Node* node);
	void inOrder(Node* node);
	void insert(Node* node, string* data);
	void searchShit(string key, Node* node,string constrain);
	void addTo1d(Node* node);
	Node** get1dArray();
	void del1dArray();
	Node* search(string key1,string key2);

};


#endif 
