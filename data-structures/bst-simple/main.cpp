// this implementation of the tree is simply written with Node class, without tree class
// functions incl. 1. insert nodes 2. print tree 3. search node 4. count nodes 5. computeHeight of node
// 6. countNullChildrenRecursive 7. countNullChildrenIterative

// ! the height of a single node is 0, NOT -1; -1 is when subtree doesn't exist, it's used when calculating balanced factor

// TODO 1.  can pass root node as const reference?

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

    Node(int data)
        : height(-1)
        , left(nullptr)
        , right(nullptr)
        , data(data) {};

    ~Node()
    {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    };
};

// 1. insert node // done
// 1.1 construct the node with correct data, remember its address
// 1.2 base case: tree is nullptr, assign new node address as root
// 1.3 if data < root, call the function on left subtree
// 1.4 if data > root, call the function on right subtree
// ! in recursive calls, the root parameters are subtree nodes
void Insert(Node*& root, const int& data)
{
    if (root == nullptr) {
        Node* newNode = new Node(data);
        root = newNode;
    } else if (data <= root->data) {
        Insert(root->left, data);
    } else {
        Insert(root->right, data);
    }
}

// 2. print tree - preOrder traversal // done
// 2.1 input: tree root node, output: cout node->data
// 2.2 if root node == nullptr, return;
// 2.3 else, std::cout << root->data;
// 2.4 call the function on left subtree, call the function on right subtree
void printTree(Node*& root)
{
    if (!root)
        return; // if root doesn't exist, exit print function

    std::cout << "(" << root->data << ", " << root->height << ") ";
    printTree(root->left);
    printTree(root->right);
};

// 3.  search function // done
// 3.1. input: tree to search (root node), data to search; return bool true is found, false if not found
// 3.2. base case: if root=nullptr return false; if data match root->data, return true;
// 3.3. if data<=root->data, call the function on left subtree
// 3.4. if data>root->data, call the function on right subtree
bool Search(Node*& root, const int& data)
{
    if (!root) {
        return false;
    }

    if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return Search(root->left, data);
    } else {
        return Search(root->right, data);
    }
}

// 4. count nodes function // done
// 4.1 input: root pointer by reference; output: the number of nodes in the tree
// 4.2 base case: if root ptr is a nullptr(false), return 0; if root ptr exists and both left and right is nullptr, return 1;
// 4.3 calculation should be sum = node count in subleft tree + node count in subright tree
// 4.4 traverse and recursion
// 4.5 test recursion & modify
int Count(Node*& root)
{
    if (!root) {
        return 0;
    }
    if (root && root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    int count = 1 + Count(root->left) + Count(root->right);
    return count;
}

// 5. computeHeight of node
// 5.1 input: tree root node by reference; couting node height and update node property height, void return
// 5.2 base case: if root ptr is nullptr, return; node class constructor doesn't set height to -1;
// 5.3 test if 3.2 base case is complete
void computeHeight(Node*& root)
{
    // base case 1
    if (!root) {
        return;
    }
    // base case 2
    if (root->left == nullptr && root->right == nullptr) {
        root->height = 0; // if you can change node class, then this is not needed because you can set height in constructor
        return;
    }

    // recursion
    if (root->left == nullptr) {
        computeHeight(root->right);
        root->height = root->right->height + 1;
    } else if (root->right == nullptr) {
        computeHeight(root->left);
        root->height = root->left->height + 1;
    } else {
        computeHeight(root->left);
        computeHeight(root->right);
        if (root->left->height >= root->right->height) {
            root->height = root->left->height + 1;
        } else {
            root->height = root->right->height + 1;
        }
    }
}

// TODO 6. countNullChildrenRecursive
// 6.1 input: root node; output: the count of this tree's nullChildren
int countNullChildrenRecursive(Node* root)
{
    return 0;
}

// TODO 7. countNullChildrenRecursive
int countNullChildrenIterative(Node* root)
{
    return 0;
}

int main()
{
    Node* n = nullptr;

    // root = new Node(15);
    // root->left = new Node(10);

    // testing insert
    Insert(n, 17);
    Insert(n, 15);
    Insert(n, 12);
    Insert(n, 20);
    Insert(n, 16);
    Insert(n, 25);
    Insert(n, 11);
    Insert(n, 13);

    // testing print
    printTree(n);
    std::cout << std::endl;

    // testing search
    std::cout << "search result: " << Search(n, 15) << std::endl; // return 1
    std::cout << "search result: " << Search(n, 16) << std::endl; // return 1
    std::cout << "search result: " << Search(n, 100) << std::endl; // return 0

    // testing count node
    std::cout << "node count: " << Count(n) << std::endl; // return 8

    // testing computeHeight
    computeHeight(n);
    printTree(n);
    std::cout << std::endl;

    // testing countNullChildrenRecursive
    std::cout << countNullChildrenRecursive(n) << std::endl; // expected output:
    std::cout << countNullChildrenIterative(n) << std::endl; // expected output:
    Insert(n, 24);
    std::cout << countNullChildrenRecursive(n) << std::endl; // expected output:
    std::cout << countNullChildrenIterative(n) << std::endl; // expected output:

    // MUST delete head node
    // ! The Node destructor will recursively delete its children nodes.
    delete n;
    n = nullptr;
    return 0;

    //! always check memory leak: leaks --atExit -- ./main
};