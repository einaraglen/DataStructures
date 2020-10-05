#include <iostream>
#include "BinaryTree.h"

//Blank constructor, sets fields to default 
BinaryTree::BinaryTree() {
	root = NULL;
    size = 0;
}

//Private insert method inserts a new node based on what leaf node we feed
void BinaryTree::insert(int key, Node* leaf) {

    if (key < leaf->key) {
        (leaf->left != NULL) ? insert(key, leaf->left) : addBlank(leaf, key, true);
    }

    else if (key >= leaf->key) {
        (leaf->right != NULL) ? insert(key, leaf->right) : addBlank(leaf, key, false);
    }
}

//Public insert only takes key to insert
void BinaryTree::insert(int key) {
    if (root != NULL) {
        insert(key, root);
    }

    else {
        root = new Node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
    }

    size++;
}

//Private addBlank adds leaf to Node n, either left or rigth
void BinaryTree::addBlank(Node* n, int key, bool left) {
    if (left) {
        n->left = new Node;
        n->left->key = key;
        n->left->left = NULL; 
        n->left->right = NULL;
    }

    else {
        n->right = new Node;
        n->right->key = key;
        n->right->left = NULL;
        n->right->right = NULL;
    }
}

//Private searchPath gives path to any node given, has to be used recurively.
std::vector<Node*> BinaryTree::searchPath(int key, std::vector<Node*> path, Node* n) {
    if (n != NULL) {
        path.push_back(n);

        if (key == n->key) {
            return path;
        }
        
        return (key < n->key) ? searchPath(key, path, n->left) : searchPath(key, path, n->right);
    }

    else {
        return path;
    }
}

//Public searchLCA uses searchPath to find paths of two Nodes and compares to see split
Node* BinaryTree::searchLCA(int a, int b) {
    std::vector<Node*> pathA, pathB;
    pathA = searchPath(a, pathA, root), pathB = searchPath(b, pathB, root);

    if (pathA.size() > 0 && pathB.size() > 0) {

        for (int i = 0; i < pathA.size() && pathB.size(); i++) {
            if (pathA[i] != pathB[i]) {
                return pathA[i - 1];
            }
        }

    }

    else {
        return NULL;
    }
}

//Private search follows tree based on rules to return search Node
Node *BinaryTree::search(int key, Node* leaf) {
    if (leaf != NULL) {
        if (key == leaf->key) {
            return leaf;
        }

        return (key < leaf->key) ? search(key, leaf->left) : search(key, leaf->right);
    }

    else {
        return NULL;
    }
}

//Public search takes key and returns Node
Node* BinaryTree::search(int key) {
    return search(key, root);
}

//Public getsize returns size(int)
int BinaryTree::getsize() {
    return size;
}

//Public getroot returns root for recursion purposes
Node* BinaryTree::getroot() {
    return root;
}