// ref: https://github.com/wadefagen/coursera/blob/master/binary-tree-traversals/ValueBinaryTree.h
#pragma once

// this version has binary tree is value based
// it stores value copies of items, rather than referecnes (`T data` rather than `T& data`)

#include <iostream>
#include <vector>

template <typename T>
class ValueBinaryTree {
public:
    // todo: why declare treenode as public?
    class TreeNode {
    public:
        T data; // this means data and dataArgument are only the same by value, they have different address; for more explanations, see examples in ref.cpp
        TreeNode* left;
        TreeNode* right;

        // initializing a treenode
        TreeNode(const T& dataArgument) // const T& dataArgument, this means dataArgument and a potential T type variable have the same address, this variable may or may not exist because you could still just construct a tree node like this `TreeNode(20)` without any additional variable, but just in case and we do need to pass in a variable in the future, we don't have to worry about the dataArgument copying its value cuz its a reference type
            : data(dataArgument)
            , left(nullptr)
            , right(nullptr) {};
    };

    ValueBinaryTree(); // done
    void createCompelteTree(const std::vector<T>& contents);
    ValueBinaryTree(const std::vector<T>& contents);
    ValueBinaryTree(const ValueBinaryTree& other); // copy constructor
    ~ValueBinaryTree(); // desctructor;

    void destroySubtree(TreeNode* subtreeRootPtr); // this function deletes the subtree rooted at the specified node; this is a recursive function.
    void destroyWholeTree();

    // traversal functions:
    void preOrder(TreeNode* cur);
    void inOrder(TreeNode* cur);
    void postOrder(TreeNode* cur);

    //  TreeNode* unsafe_getRootPtr() {
    //   return root_;
    // todo: what's the point of this function?

private:
    TreeNode* root_;
};

#include "ValueBinaryTree.hpp"
