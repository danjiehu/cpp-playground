// this file is to demostrate the const keyword use in pointers

// *** summary ***
// ! Read it backwards (as driven by Clockwise/Spiral Rule):
// int* - pointer to int
// int const * - pointer to const int
// int * const - const pointer to int
// int const * const - const pointer to const int
// Now the first const can be on either side of the type so:
// const int * == int const * // it does not change the read it backward principle
// ref: https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const

#include <iostream>

int main()
{
    int* const p = new int; // ! this is a const pointer to int, therefore you cannot reassign it to nullptr later
    const int q = 5;
    *p = q + q;

    std::cout << *p << std::endl;

    delete p;
    p = nullptr; // ! error: variable 'p' declared const here

    return 0;
}