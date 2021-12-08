// ref: https://www.geeksforgeeks.org/data-structures/linked-list/#singlyLinkedList
// ref: https://github.com/wadefagen/coursera/tree/master/linked-memory
// ref: https://github.com/gsprint23/Cpp-Crash-Course/tree/master/TemplatedLinkedListFun, https://www.youtube.com/watch?v=UD1Ingv1qbQ

// !!! in linked list, you modified ALL nodes by assessing and using the pointer stored at inside the PREVIOUS NODE, or head_ if you want to modify the first node
// TODO: learn unique pointer and replace all heap pointer with unique pointer

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

public:
    // public contains: class function declaration incl. [] operator, functions such as insertAtFront, constructor, destructor
    List();
    ~List();

    void insertAtFront(const T& newValue);
    void displayList();
    unsigned size();
    const T& operator[](unsigned index);
    void appendNode(const T&);
    void deleteAtFront();
    void deleteAtEnd();
    ListNode* search(const T& value);
    void deleteNode(const T& value);
    void insertOrdered(const T& newValue); // TODO
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
    while (ptr != nullptr) {
        toDelete = ptr;
        ptr = ptr->next_ptr; // obtained the next node pointer address before deleting ptrent code
        delete toDelete;
        toDelete = nullptr;
    }
    cout << "~List() destructor called" << endl;
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

    // ! (ptr->next_ptr != nullptr) ends with `ptr->next_ptr = nullptr`, i.e. when while loop scope ends, ptr now points to last node, ptr is the same value as the second to last node's next_ptr which points to the last node, last node content hasn't been looped over inside the while loop scope {}
    // ! (ptr != nullptr) ends with `ptr = nullptr`, i.e. when while loop scope ends, ptr is the nullptr of last node, last node content HAS been looped over inside the while loop scope {}
    // when while loop terminates, test conditions is false, for example if test condition is (ptr != nullptr), when code ends, ptr == nullptr.
    // !!! in linked list, you modified ALL nodes by assessing and using the pointer stored at inside the PREVIOUS NODE, or head_ if you want to modify the first node
    // while loop flow chart: https://www.programiz.com/cpp-programming/do-while-loop
    // ref: https://stackoverflow.com/questions/18835868/traversing-through-a-linked-list-whileptr-null-vs-whileptr-next-null

    ptr->next_ptr = newNode;
}

// 7. deleteAtFront() function
// TODO: check memory leak here
template <typename T>
void List<T>::deleteAtFront()
{
    if (head_ != nullptr) {
        ListNode* newFirstNode = head_->next_ptr;
        delete head_;
        head_ = nullptr;

        head_ = newFirstNode;
    }
}

// 8. deleteAtEnd() function
// ! why segmentation fault without ptr_toPrev:
// ! once ptr_toCurr (which is pointed to last node) is deleted, you are NOT allowed to access this address anymore with ptr_toCurr
// ! BUT, second to last node still have this address, `ptr_toCurr` is a separate variable, setting it to null doesn't change the address stored in second to last node `next_ptr`
// ! and you can only modify second to last node with address stored in third to last node (BECAUSE THIS IS WHAT LINKED LIST IS)
template <typename T>
void List<T>::deleteAtEnd()
{
    if (head_ != nullptr) {
        // list is not empty
        // need to traverse list, stopping at the last node
        ListNode* ptr_toCurr = head_;
        ListNode* ptr_toPrev = nullptr;
        while (ptr_toCurr->next_ptr != nullptr) { // use ptr_toCurr->next_ptr != nullptr because you need to access the pointer to last node
            ptr_toPrev = ptr_toCurr;
            ptr_toCurr = ptr_toCurr->next_ptr;
        }
        if (ptr_toPrev == nullptr) {
            delete head_;
            head_ = nullptr;
        } else {
            delete ptr_toCurr;
            ptr_toCurr = nullptr;
            ptr_toPrev->next_ptr = nullptr;
        }
    }
}

// 9. search function
// find and return the ListNode (ptr to the ListNode) with searched value and `nullptr` is value is not found
template <typename T>
typename List<T>::ListNode* List<T>::search(const T& value) // TODO learn syntax: missing 'typename' prior to dependent type name 'List<T>::ListNode'
{
    ListNode* ptr = head_;
    int count = 0;
    while (ptr != nullptr) {
        if (ptr->node_data == value) {
            std::cout << "found node_data at index " << count << endl;
            return ptr;
        } else {
            ptr = ptr->next_ptr;
            count++;
        }
    }

    std::cout << "no such data found" << endl;
    return nullptr;
}

// 10. void deleteNode(const T&) function
template <typename T>
void List<T>::deleteNode(const T& value)
{
    ListNode* ptr = head_;
    ListNode* prev_ptr = nullptr;
    // head match
    // end match
    // middle match
    while (ptr != nullptr) {
        if (ptr->node_data == value && ptr == head_) {
            ListNode* temp = ptr->next_ptr;
            delete ptr;
            ptr = nullptr;
            head_ = temp;
        } else if (ptr->node_data == value) {
            ListNode* temp = ptr->next_ptr;
            delete ptr;
            ptr = nullptr;
            prev_ptr->next_ptr = temp;
        } else {
            prev_ptr = ptr;
            ptr = ptr->next_ptr;
        }
    }
}

// // 11. insertOrdered()
// template <typename T>
// void List<T>::insertOrdered(const T& newValue)
// {
//     // if size = 0
//     // if size = 1
//     // if size > 1

//     if (head_ == nullptr) {
//         this->insertAtFront(newValue);
//     } else if (this->size() == 1) {
//         if (newValue <= head_->node_data) {
//             this->insertAtFront(newValue);
//         } else {
//             this->appendNode(newValue);
//         }
//     } else {
//         // if it's the head, push front
//         // if it's not the head relink
//         if (newValue <= head_->node_data) {
//             this->insertAtFront(newValue);
//         } else if (newValue > tail_->data) {
//             this->pushBack(newValue);
//         } else {
//             Node* pre_thru = head_;
//             Node* thru = head_->next;
//             while (thru != nullptr) {
//                 if (newValue <= thru->data) {
//                     Node* nodeToInsert = new Node(newValue);
//                     nodeToInsert->prev = pre_thru;
//                     nodeToInsert->next = thru;
//                     size_++;
//                 } else {
//                     pre_thru = thru;
//                     thru = thru->next;
//                 }
//             }
//         }
//     }
// }