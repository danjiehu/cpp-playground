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

// declaration
template <typename T>
class List {
public:
    // public contains: class function declaration incl. [] operator, functions such as insertAtFront, constructor, destructor
    void insertAtFront(const T& data);
    // constructor - make sure head_is null-initialized
    List()
        : head_(nullptr) {};
    // destructor - free the memory allocated for ListNode objects when the List is destroyed
    ~List()
    {
        ListNode* thru = head_;
    }

private:
    // private contains:  variables incl. ListNode class, ListNode head pointer (tail is nullptr), function such as search data
    // nested class ListNode
    class ListNode {
    public:
        // if declared as private, List functions can't access it
        // ref: https://www.geeksforgeeks.org/nested-classes-in-c/
        T m_data;
        ListNode* m_next;
        // ListNode constructor: m_data takes in data, m_next takes on nullptr
        // passing by reference doesn't create copy, passing by const promise not to change the passed-in data in the constructor function
        ListNode(const T& data)
            : m_data(data)
            , m_next(nullptr) {};
    };

    ListNode* head_;
};

// definition
// ! templated C++ code generally needs to be written entirely in header files, that's why we define the functions in header file, not cpp file here
