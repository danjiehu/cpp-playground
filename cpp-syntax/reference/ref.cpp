#include <iostream>

int main()
{
    int* ptr;
    int var = 7;
    int foo = 21;
    ptr = &var;
    ptr = &foo;
    int& ref = var;

    std::cin.get();
}
