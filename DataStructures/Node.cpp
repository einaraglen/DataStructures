#include <iostream>
#include "Node.h"

Node::Node() {
	key = NULL;
	left = NULL;
	right = NULL;
}

Node::Node(int key) {
	Node n;
	n.key = key;
}