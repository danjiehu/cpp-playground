// ref: https://github.com/wadefagen/coursera/blob/master/binary-tree-traversals/ValueBinaryTree.h
#pragma once

// this version has binary tree is value based
// it stores value copies of items, rather than referecnes (`T data` rather than `T& data`)

template <typename T>
class BinaryTree {
public:
    // constructor;
    // destructor;

private:
    // nested class all is public
    class TreeNode {
    public:
        T& data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T& data)
            : data(data)
            , left(nullptr)
            , right(nullptr) {};
    }

    TreeNode* root_;
};
