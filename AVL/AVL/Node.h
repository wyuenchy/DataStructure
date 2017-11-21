#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
public:
	int key;
	int height;
	Node* left;
	Node* right;
	Node(int d);
};


#endif