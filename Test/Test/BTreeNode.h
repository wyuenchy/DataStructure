#ifndef BTREENODE_H
#define BTREENODE_H

#include <iostream>
using namespace std;

class BTreeNode
{
public:
	bool leaf; //T is leaf
	int minDegree;
	int *keys;	//key array
	BTreeNode **ChildPointer;
	int currNumKey;

	BTreeNode(int degree,bool leaf);
	void traverse();
	BTreeNode *search(int num);

	void insertNonFull(int num);
	void spliteChild(int x,BTreeNode *y);
};

#endif