

#ifndef  AVLTREE_H
#define	AVLTREE_H
#include "Node.h"
#include <string>

class AVLTree {

public:
	Node* root;
	Node** fucking1DArray;
	AVLTree();

	void insert(Node* node, string* data);

	void addTo1d(Node* node);
	Node** get1dArray();
	void del1dArray();
	void searchShit(string key, Node* node, string constrain);
	Node* search(string key1, string key2);
	void inOrder(Node* node);

	void deleteN(Node* node,string* data);


};


#endif 
