// ref: https://www.geeksforgeeks.org/data-structures/linked-list/#singlyLinkedList
// ref: https://github.com/wadefagen/coursera/tree/master/linked-memory
// ref: https://github.com/gsprint23/Cpp-Crash-Course/tree/master/TemplatedLinkedListFun, https://www.youtube.com/watch?v=UD1Ingv1qbQ

// highlights:
// ! 1. linked list - nodes are created on heap, therefore, they must be destroyed in custom destructor
// 2. you can use valgrind to track memory link, ref: https://valgrind.org/docs/manual/mc-manual.html#mc-manual.leaks
// `valgrind --leak-check=full -v ./your_program`

// side notes:
// 1. class have a default private specifier, i.e.
// class A
// {
//    void foo(); //private
// };

#pragma once

#include <iostream>

// ! declaration
template <typename T>
class List {
public:
    // public contains: class function declaration incl. [] operator, functions such as insertAtFront, constructor, destructor
    List();
    ~List();

    const T& operator[](unsigned index);
    void insertAtFront(const T&);
    void displayList();
    void appendNode(const T&);
    void deleteAtFront();
    void deleteAtEnd();
    void deleteNode(const T&);
    void search(const T&);

private:
    // private contains:  variables incl. ListNode class, ListNode head pointer (tail is nullptr), function such as search data
    // nested class ListNode
    class ListNode {
    public:
        // if declared as private, List functions can't access it
        // ref: https://www.geeksforgeeks.org/nested-classes-in-c/
        T node_data;
        ListNode* next_ptr;

        // ListNode default constructor: node_data takes in data, next_ptr takes on nullptr
        ListNode(const T& data)
            : node_data(data)
            , next_ptr(nullptr) {};
    };

    // ListNode pointer type: head pointer
    ListNode* head_;
};

// ! definition
// ! templated C++ code generally needs to be written entirely in header files, that's why we define the functions in header file, not cpp file here
// or you can separate them into .h and .hpp file just for your own organization, for example append `#include "List.hpp"` at the end, ref: https://github.com/wadefagen/coursera/tree/master/linked-memory
// 1. custom default constructor
template <typename T>
List<T>::List()
    : head_(nullptr) {};

// 2. custom default destructor - required for all class with heap allocation
template <typename T> // TODO: use valgrind to check memory leak (effectiveness of the destructor)
List<T>::~List()
{
    ListNode* curr = head_;
    ListNode* toDelete;
    while (curr != nullptr) {
        toDelete = curr;
        curr = curr->next; // obtained the next node pointer address before deleting current code
        delete toDelete;
        toDelete = nullptr;
    }
}

template <typename T>
List<T>::insertAtFront(const T& newNode)
{
}