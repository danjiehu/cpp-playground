// 1. how to create a inheritance class
// 2. can a inherited class use parent class members?
// 3. can parent class use inherited class members?
#include "Cube.h"
#include <iostream>

int main()
{
    Cube c("purple", 2);
    std::cout << c.getVolume() << std::endl;

    return 0;
}