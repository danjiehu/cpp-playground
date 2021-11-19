#include "log.h"
#include <iostream>
#include <string>

int main()
{
    // stack memory
    int a = 10;
    a++;
    std::string string = "Hello";

    // heap memory
    int* stack_ptr = new int;
    *stack_ptr = 4;
    int& v = *stack_ptr; // set `v` to reference the address `stack_ptr` points to
    v = 4; // syntax `v` represents the value stored on that address
    // ! for reference variable, call directly its name and it means the value on that address
    delete stack_ptr; //? this line of code didn't change anything, what does it do?
    stack_ptr = nullptr;

    for (int i = 0; i < 5; i++) {
        const char c = string[i];
        std::cout << c << std::endl;
    }

    Log("1-hello world!");
    Log("2-hello world!");
    std::cin.get();
    Log("3-hello world!");
    Log("4-hello world!");
}