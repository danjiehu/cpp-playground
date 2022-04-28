// this code is to demostrate the invalid use of returning local variables in a function, including local pointers
#include <iostream>

// demo-1
// int* func(const int& a)
// {
//     int b = a;
//     return &b; // warning: this is returning a stack memory address that is discarded after function lifetime ends
// }

// demo-2
// int* func_2(const int& a)
// {
//     int* b = new int(a);
//     return b; // ! this is also returning a stack variable, b is a stack variable
// }

// demo-3
// ! this is the valid use of heap allocation
int func_3(const int& a)
{
    int* b = new int(a);
    int c = *b;
    delete b; // taking care of memory leak
    b = nullptr;

    return c; // not returning stack memory address
}

int main()
{
    // return an address to a pointer type function
    // std::cout << *(func(101)) << std::endl; // ! cause warning
    // std::cout << *(func_2(102)) << std::endl; // ! cause same warning
    std::cout << func_3(103) << std::endl;
    return 0;
}