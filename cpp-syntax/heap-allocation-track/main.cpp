#include <iostream>

int nodeCount = 0;

// using a simple BST structure
struct Node {
    int key;
    Node* left;
    Node* right;

    Node()
        : key(-1)
        , left(nullptr)
        , right(nullptr)
    {
        nodeCount++;
    };

    Node(int value)
        : key(value)
        , left(nullptr)
        , right(nullptr)
    {
        nodeCount++;
    };

    ~Node()
    {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
        nodeCount--;
    }
};

int main()
{
    std::cout << nodeCount << std::endl;
    Node* root = new Node(20); // 0
    std::cout << nodeCount << std::endl; // 1

    root->left = new Node(10);
    root->right = new Node(30);
    std::cout << nodeCount << std::endl; // 3

    root->left->left = new Node(10);
    root->left->right = new Node(30);
    std::cout << nodeCount << std::endl; // 5

    delete root; // 0
    root = nullptr;
    std::cout << nodeCount << std::endl;

    return 0;
}