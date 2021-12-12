// ref: https://github.com/wadefagen/coursera/blob/master/binary-tree-traversals/ValueBinaryTree.h
#pragma once

// this version has binary tree is value based
// it stores value copies of items, rather than referecnes (`T data` rather than `T& data`)

template <typename T>
class BinaryTree {
public:
    // todo: why declare treenode as public?
    class TreeNode {
    public:
        T data;
        TreeNode* left;
        TreeNode* right;

        // initializing a treenode
        // ! constructor makes a copy of "dataArgument" and initialize "data" with its value
        // int data;
        // const int& dataArgument = 8;
        //
        // T data = dataArgument
        TreeNode(const T& dataArgument)
            : data(dataArgument)
            , left(nullptr)
            , right(nullptr) {};
    }

    TreeNode* root_;

private:
};
