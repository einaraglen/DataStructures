#include <iostream>
#include "ArrayList.cpp"
#include "BinaryTree.h"

int main() {
    BinaryTree tree;
    //1
    tree.insert(8);
    //2
    tree.insert(3);
    tree.insert(10);
    //3
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    //4
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    tree.insert(15);

    tree.insert(2);
    tree.insert(5);

    //std::cout << tree.findLCA(1, 6) << std::endl; //3
    //std::cout << tree.findLCANode(tree.getroot(), 5, 2)->key << std::endl; //3
    Node *n = tree.searchLCA(1, 2);
    if (n == NULL) {
        std::cout << "No path" << std::endl;
    }

    else {
        std::cout << n->key << std::endl;
    }
}
