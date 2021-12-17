// TODO: this is an unfinished demo
#pragma once

#include "ValueBinaryTree.h"

// 1. ValueBinaryTree(); default constructor
template <typename T>
ValueBinaryTree<T>::ValueBinaryTree()
    : root_(nullptr) {};

// TODO 2. createCompleteTree function - will be used in custom contstructor so write it first
// code in en:
// step 1. clear the whole tree in case there's something there
// step 2. check if vector is empty, if so, leave the tree empty
// step 3. if vector is not empty, construct first treenode with first element, assign it as head_
// step 4. construct the second treenode with the second vector element, if it's larger than first element, assign its address as prev node's right pointer, else assign its address as prev node's left pointer
// step 5. construct the third treenode with the third vector element, if it's larger than prev element, assign its address as prev node's right pointer, else assign its address as prev node's left pointer
// ... repeat untill all elements in vector are used to construct treenode
template <typename T>
void ValueBinaryTree<T>::createCompelteTree(const std::vector<T>& contents)
{
}

// 3. ValueBinaryTree(const std::vector<T>& contents); custom constructor
template <typename T>
ValueBinaryTree<T>::ValueBinaryTree(const std::vector<T>& contents)
{
    createCompleteTree(contents);
}
