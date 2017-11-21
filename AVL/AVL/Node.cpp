#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int d) {
	key = d;
	height = 1;
	left = right = NULL;
}