#include "log.h"
#include <iostream>
#include <string>

int main()
{
    int a = 8;
    a++;
    std::string string = "Hello";

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