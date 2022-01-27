#include <iostream>

// pitfall-1: declare pointer without initialization
// int * iPtr; // this is pointing to an invalid address
// *iPtr = 55; // can't find the invalid address, will throw error
// cout << *iPtr << endl;
// YOU CAN'T DECLARE A POINTER WITHOUT INITIALIZATION!

int main()
{
    return 0;
}