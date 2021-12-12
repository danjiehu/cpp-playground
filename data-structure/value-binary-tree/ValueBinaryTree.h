#pragma once

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
