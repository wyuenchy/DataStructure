#include <string>
#include <iostream>
#include "BTreeNode.h"
using namespace std;


BTreeNode::BTreeNode(int degree,bool leaf) {
	minDegree = degree;
	this->leaf = leaf;
														//MaxDegree=6
	keys = new int[2*minDegree-1];						// e.g array[5] 
	ChildPointer = new BTreeNode *[2*minDegree];			// have 6 pointer
	currNumKey = 0;										// Initialize the number of keys as 0
}


void BTreeNode::traverse() {
	int i;
	for (i = 0; i < currNumKey;i++) {
		if (leaf==false) {								//if current node is not a leaf traverse the chilpointer
			ChildPointer[i]->traverse();				//recursive
		}
		cout << " " << keys[i];
	}

	if (leaf == false) {
		ChildPointer[i]->traverse();
	}
}

BTreeNode*BTreeNode::search(int num) {
	int i = 0;
	while (i<currNumKey&&num>keys[i]) {			//loop through the keys
		i++;
	}

	if (keys[i] == num) {
		return this;						//found, return the node
	}

	if (leaf == true) {
		return NULL;							//not found
	}

	return ChildPointer[i]->search(num);		//recursive
}


void BTreeNode::insertNonFull(int num) {
	int i = currNumKey - 1;

	//if is leaf
	if (leaf==true) {

		while (i >= 0 && keys[i] > num) {
			keys[i + 1] = keys[i];			//copy the current key to next place
			i--;
		}

		keys[i + 1] = num;					//insert 
		currNumKey++;
	}

	//if not leaf
	else {
		while (i >= 0 && keys[i] > num) {
			i--;
		}

		//check if the child is full
		if (ChildPointer[i+1]->currNumKey==5) {
			spliteChild(i + 1, ChildPointer[i + 1]);
			if (keys[i+1]<num) {
				i++;
			}
		}
		ChildPointer[i + 1]->insertNonFull(num);
	}
}


void BTreeNode::spliteChild(int x, BTreeNode*y) {
	BTreeNode* newNode = new BTreeNode(y->minDegree, y->leaf);
	newNode->currNumKey = minDegree - 1;


	for (int j = 0; j < minDegree-1; j++) {
		newNode->keys[j] = y->keys[j + minDegree];
	}

	if (y->leaf == false) {
		for (int j = 0; j < minDegree; j++) {
			newNode->ChildPointer[j] = y->ChildPointer[j + minDegree];
		}
	}

	//reduce the number of keys in y
	y->currNumKey = minDegree-1;

	for (int j = currNumKey; j >= x + 1;j--) {
		ChildPointer[j + 1] = ChildPointer[j];
	}

	ChildPointer[x + 1] = newNode;

	for (int j = currNumKey-1; j >= x;j--) {
		keys[j + 1] = keys[j];
	}

	keys[x] = y->keys[minDegree - 1];

	currNumKey++;
}