#ifndef BTREE_H
#define BTREE_H



#include "BTreeNode.h"
using namespace std;

class BTree
{
private:
	BTreeNode *root;		//pointer to root Node 
	int minDegree;

public:
	BTree(int degree);
	void traverse();
	BTreeNode* search(int num);


	void insert(int num);
};


#endif