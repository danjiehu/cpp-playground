// ** important notes: **//
// ! there are two situations when a function variable outlives an function,
// 1. the paramter passed is reference type, this can only be seen in the function definition
// 2. the variable is created inside the function body as a heap allocated variable; this can be seen inside function body definition with new keyword.
// the use of each should be clear by now:
// 1. if the function intention is to create an object anew i.e. it doesn't exist by the of function execution, and the object needs to outlive the function, use heap allocation
// 2. if the object to outlive is a function parameter and the object has ALREADY been created, use reference

#include <iostream>
// reference has nothing to do with heap allocation, or the use of a pointer,
// distinguish their differences below
// dereference has to do with pointer
void funcV(int* x) // ! x is a local variable that is discarded after the function ends, because this is not passing by reference this is passing by value
{
    int* y = new int;
    *y = 16;
    x = y; // x is same value as y now;
    delete y; // destroy heap int 16;
    // x goes out of scope, x is destroyped
}

void funcR(int*& x) // ! x is a local variable that is discarded after the function ends, because this is not passing by reference this is passing by value
{
    int* y = new int;
    *y = 16;
    x = y; // assigning y's value (heap address value) to x
    std::cout << "funcR y value as of now: " << y << std::endl;
    delete y; // destroy heap int 16;
    // x is now the heap address value
}

int main()
{
    //* pointer example-1
    int* y;
    int x = 36;
    y = &x;
    (*y)++;
    std::cout << x << std::endl; // expect: 37 // y points to x's address
    std::cout << *y << std::endl; // expect: 37 // dereferenced pointer is the value at which the pointer points to

    //* pointer type function parameter passed by value pointer type example-2
    int i = 9;
    funcV(&i); // this is passing i's address as parameter, it is NOT creating a reference
    std::cout << i << std::endl; // expect: 9

    //* pointer type function parameter passed by reference pointer type example-3
    //! the key is at funciton definition
    int j = 9;
    int* j_address = &j; // ! j_address is an independent stack variable that temporarily stores the address of j
    std::cout << "checking j_address before funcR: " << &j << std::endl; // expect: error or random value
    funcR(j_address);
    // ! note how you cannot use simple &j here for pointer reference parameter the other side of the reference type MUST be a variable that's already initialized
    std::cout << "checking j_address after funcR: " << j_address << std::endl; // expect: same as funcR y value
    std::cout << "checking j: " << j << std::endl; // expect: 6
    std::cout << "checking &j: " << &j << std::endl; // expect: same as j_address before funcR

    //* heap allocation example-4
    // no new no heap!!!
    int* heap_var = new int;
    *heap_var = 22;
    std::cout << heap_var << std::endl; // expect a heap address small
    std::cout << &heap_var << std::endl; // expect a stack address large
    std::cout << *heap_var << std::endl; // expect 22
    delete heap_var;
    std::cout << heap_var << std::endl; // expect the same heap address // ! note how the heap address is still recognized
    std::cout << &heap_var << std::endl; // expect the same stack address // ! note how the stack address is still recognized
    std::cout << *heap_var << std::endl; // expect error or random value, every runtime could be different
    heap_var = nullptr;
    std::cout << heap_var << std::endl; // expect 0x0 for nullptr
    std::cout << &heap_var << std::endl; // expect the same stack address
    // std::cout << *heap_var << std::endl; // ! expect segmentation fault for dereferencing nullptr

    //* reference example-5
    // ! reference has to reference an existing variable with value, the other side can NOT be address
    int a = 30;
    int& b = a;
    std::cout << "a is int type, value is: " << a << std::endl;
    std::cout << "b is int reference type, value is: " << b << std::endl;
    std::cout << "a's address is: " << &a << std::endl;
    std::cout << "b's address is: " << &b << std::endl; // the same as a

    return 0;
}
