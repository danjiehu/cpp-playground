// this program will not compile and run intentionally to demostrate how declaring two variables in the same line could cause confusion and mistakes (line 7)
#include <iostream>
#include <typeinfo>

int main()
{
    int *x, y; // ! y is a integer, NOT a pointer
    std::cout << "x type is: " << typeid(x).name() << std::endl; // output pi: pointer to integer
    std::cout << "y type is: " << typeid(y).name() << std::endl; // output i: integer

    int z = 10;
    x = &z;
    std::cout << x << std::endl;
    y = x; // ! error: cannot conver pointer to int
    *x = 15;
    std::cout << z << std::endl;
    // my intial reaction is will print z as 15 but there is a very tricky part at `int *x, y;` x and y are NOT both pointers to integer, y is a integer.
    // so the code will NOT compile and run at line `y=x`, error:  incompatible pointer to integer conversion assigning to 'int' from 'int *'; dereference with *

    return 0;
}