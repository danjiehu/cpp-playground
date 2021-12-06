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

using std::cout;
using std::endl;

// ! declaration
template <typename T>
class List {
public:
    // public contains: class function declaration incl. [] operator, functions such as insertAtFront, constructor, destructor
    List();
    ~List();

    void insertAtFront(const T&); // done
    void displayList(); // done
    unsigned size(); // done
    const T& operator[](unsigned index); // done
    void appendNode(const T&); // done
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
    ListNode* ptr = head_;
    ListNode* toDelete;
    while (ptr->next_ptr != nullptr) {
        toDelete = ptr;
        ptr = ptr->next_ptr; // obtained the next node pointer address before deleting ptrent code
        delete toDelete;
        toDelete = nullptr;
    }
}

// 3. insertAtFront() function
template <typename T>
void List<T>::insertAtFront(const T& newValue)
{
    ListNode* newNode = new ListNode(newValue); // create a newNode on heap
    // newNode->node_data = newValue; // assign new value to newNode's data

    if (head_ == nullptr) {
        head_ = newNode; // assign head pointer to point to newNode, newNode by default alreday points to null, that's it
    } else {
        newNode->next_ptr = head_; // new node's next_ptr points to original first node
        head_ = newNode; // reassign head point to point to new node
    }
}

// 4. displayList() function
template <typename T>
void List<T>::displayList()
{
    ListNode* ptr = head_;

    cout << "head->";
    while (ptr != nullptr) {
        cout << ptr->node_data << "->";
        ptr = ptr->next_ptr;
    };

    cout << "null" << endl;
}

// 5. size() function
template <typename T>
unsigned List<T>::size()
{
    unsigned size = 0;
    ListNode* ptr = head_;

    while (ptr != nullptr) {
        ptr = ptr->next_ptr;
        size++;
    };

    return size;
}

// 6. operator[] overload
template <typename T>
const T& List<T>::operator[](unsigned index)
{

    ListNode* ptr = head_;

    while (index > 0) {
        ptr = ptr->next_ptr;
        index--;
    }

    return ptr->node_data;
}

// 6. appendNode() function - fix bug
template <typename T>
void List<T>::appendNode(const T& newValue)
{
    ListNode* newNode = new ListNode(newValue);
    ListNode* ptr = head_;

    while (ptr->next_ptr != nullptr) {
        ptr = ptr->next_ptr;
    } // found the original last node pointer

    // ! (ptr->next_ptr != nullptr) ends with `ptr->next_ptr = nullptr`, i.e. when while loop scope ends, ptr points to last node, ptr is the same value as the second to last node's next_ptr, last node content hasn't been looped over with the while loop scope {}
    // ! (ptr != nullptr) ends with `ptr = nullptr`, i.e. when while loop scope ends, ptr is the nullptr of last node, last node content HAS been looped over inside the while loop scope {}
    // ref: https://stackoverflow.com/questions/18835868/traversing-through-a-linked-list-whileptr-null-vs-whileptr-next-null

    ptr->next_ptr = newNode;
}
