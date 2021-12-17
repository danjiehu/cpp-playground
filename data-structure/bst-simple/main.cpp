// this implementation of the tree is simply written with Node class, without tree class
// functions incl. 1. insert nodes 2. print tree 3. count nodes 4. computeHeight of node
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

main()
{
    Node* n = new Node();

    // MUST delete head node
    // ! The Node destructor will recursively delete its children nodes.
    delete n;
    n = nullptr;
    return 0;
};