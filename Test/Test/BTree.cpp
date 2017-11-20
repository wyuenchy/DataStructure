#include <string>
#include <iostream>
#include "BTreeNode.h"
#include "BTree.h"
using namespace std;




BTree::BTree(int degree)
{
	root = NULL;
	minDegree = degree;
}

void BTree::traverse() {
	if (root!=NULL) {			//if BtreeNode not null
		root->traverse();		//BtreeNode traverse
	}
}



BTreeNode* BTree::search(int num) {
	if (root==NULL) {
		return root;
	}
	else
	{
		return root->search(num);
	}

}

void BTree::insert(int num) {
	//empty Tree
	if (root==NULL) {
		root = new BTreeNode(minDegree, true);	//create a BTreeNode
		root->keys[0] = num;					//insert the num in keys[0]
		root->currNumKey = 1;					//update the currNumOfKey 
	}
	else {
		//the keys is not full
		if (root->currNumKey!=2*minDegree-1) {
			root->insertNonFull(num);
		}
		// the keys is full
		else {
			BTreeNode* newNode = new BTreeNode(minDegree, false);
			newNode->ChildPointer[0] = root;
			newNode->spliteChild(0, root);

			int i = 0;
			if (newNode->keys[0]<num) {
				i++;
			}
			newNode->ChildPointer[i]->insertNonFull(num);
			root = newNode;
			
		}

	}
}
