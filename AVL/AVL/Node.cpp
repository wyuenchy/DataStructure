#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int k) {
	key = k;
	height = 1;
	left = right = NULL;
}
