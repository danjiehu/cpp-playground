// c++ uses default cosntructor, copy constructor and assignment operator if a custom one is not defined
// ! check shallow-copy and deep-copy demo for the reason why we need to write custom copy operator and assignment operators when there are heap allocated class member variables
#include <iostream>

class Cube {
public:
    // constructor
    Cube();
    Cube(int leng);

    // copy constructor
    Cube(const Cube& other);

    // assignemnt operator
    Cube& operator=(const Cube& other);

    // destructor
    // ~Cube();

private:
    int length_;
};

Cube::Cube()
{
    length_ = 1;
    std::cout << "Cube() constructor invoked!" << std::endl;
}

Cube::Cube(int leng)
    : length_(leng)
{
    std::cout << "Cube(int leng) constructor invoked!" << std::endl;
}

// * custom copy constructor definition syntax
// ! function objective: to CREATE an new object by copying the values of an existing object of the same type, examples:
// 1. direct copying an existing object to CREATE an new object
// 2. function argument by value
// 3. return an object by value (the function return type is NOT reference)
Cube::Cube(const Cube& other)
    : length_(other.length_)
{
    std::cout << "custom copy constructor invoked!" << std::endl;
}

// * customer assignment operator function syntax
// ! function objective: to modify/replace the (assignment operator) leftside object values directly by giving it an rightside object to copy
// why function return type is object reference: so that the changes made is on the leftside object directly
Cube& Cube::operator=(const Cube& other)
{
    length_ = other.length_;
    std::cout << "custom assignment operator invoked!" << std::endl;
    return *this; // ! remember to return
}

void cubeArg(Cube c)
{
    // do nothing
}

Cube returnCubebyValue(Cube c)
{
    return c;
}

int main()
{
    Cube baseCube(22);

    // * copy constructor invocaiton example-1: construct by copying directly
    Cube c = baseCube;
    std::cout << "end of copy constructor example-1" << std::endl;

    // * copy constructor invocation example-2: function argument
    cubeArg(baseCube);
    std::cout << "end of copy constructor example-2" << std::endl;

    // * copy constructor invocation example-3: return cube by value
    returnCubebyValue(baseCube);
    // ! here invoked copy constructor twice, one when passing as argu, one when return Cube by value
    std::cout << "end of copy constructor example-3" << std::endl;

    // * assignment operator invocation example-1
    Cube newCube(23);
    c = newCube;
    std::cout << "end of assignment operator example-1" << std::endl;

    return 0;
}