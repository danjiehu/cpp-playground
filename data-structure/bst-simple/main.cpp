// this implementation of the tree is simply written with Node class, without tree class
// functions incl. 1. insert nodes 2. print tree 3. count nodes 4. computeHeight of node
// memory leak check: leaks --atExit -- ./main

#include <iostream>

struct Node {
    int data;
    int height;

    Node* left;
    Node* right;
    Node()
        : height(-1)
        , left(nullptr)
        , right(nullptr) {};
    ~Node()
    {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    };
};

// TODO

int main()
{
    Node* n = new Node();

    n->left = new Node();
    n->right = new Node();
    n->right->left = new Node();
    n->right->right = new Node();
    n->right->right->right = new Node();

    // MUST delete head node
    // ! The Node destructor will recursively delete its children nodes.
    delete n;
    n = nullptr;
    return 0;
};