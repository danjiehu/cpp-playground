// demo objective:
// once a custom constructor is defined, the automatic constructor if not define, it doesn’t exist anymore
// but if none is defined, Cube c0 compiles
#include <iostream>

class Cube {
public:
    Cube(int leng)
        : length_(leng) {};

private:
    int length_;
};

int main()
{
    Cube c0;
    // if Cube(int leng) is defined - error: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 0 were provided
    // if no constructor is defined - code compiles with no problem

    return 0;
}