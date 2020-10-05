#pragma once
#include <iostream>
#include <vector>
#include "Node.h"

class BinaryTree {
public:
	BinaryTree();
	void insert(int key);
	Node* search(int key);
	int findLCA(int a, int b);
	Node* findLCANode(Node* root, int a, int b);
	int getsize();
	Node* getroot();
	Node* searchLCA(int a, int b);

private:
	void insert(int key, Node* leaf);
	Node* search(int key, Node* leaf);
	std::vector<Node*> searchPath(int key, std::vector<Node*> path, Node* leaf);
	bool findPath(Node* start, std::vector<int> &path, int key);
	Node* root;
	int size;
	void addBlank(Node* n, int key, bool left);
};


