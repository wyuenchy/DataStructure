

#ifndef  AVLTREE_H
#define	AVLTREE_H
#include "Node.h"

class AVLTree{

public:
	AVLTree();
	Node* root;
	string** fucking2DArray;
	void preOrder(Node* node);
	void inOrder(Node* node);
	void insert(Node* node, string* data);
	void searchShit(string key, Node* node, int i);
	void addTo2d(Node* node);
	string** get2dArray();
	void del2dArray();
	Node* search(string key1,string key2);

};


#endif 
