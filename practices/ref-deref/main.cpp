#include <iostream>
// reference has nothing to do with heap allocation, or the use of a pointer,
// distinguish their differences below
// dereference has to do with pointer

int main()
{
    // pointer example
    int* y;
    int x = 36;
    y = &x;
    (*y)++;
    std::cout << x << std::endl; // expect: 37 // y points to x's address
    std::cout << *y << std::endl; // expect: 37 // dereferenced pointer is the value at which the pointer points to

    // heap allocation example
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
    std::cout << *heap_var << std::endl; // ! expect segmentation fault for dereferencing nullptr

    // reference example
    // ! reference has to reference an existing variable with value, the other side can NOT be address
    // todo

    return 0;
}
