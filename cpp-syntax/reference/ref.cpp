#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // 1. basic usage
    int* ptr; // created stack variable, address is 0xA, name is ptr, value is uninialized, it's ready to take on an address that store the value of an integer
    int var = 7; // created stack variable, address is 0xB, name is var, value is 7
    int foo = 21; // created stack variable, address is 0xC, name is var, value is 7
    ptr = &var; // assign 0xB to be the value of ptr
    ptr = &foo; // assign 0xC to be the value of ptr
    int& ref = var; // created stack variable, address is 0xB, name is ref (also is var), value is 7 (it gave 0xB a different name)
    // ! since a reference is an alias, the variable it's aliasing needs to be exist at initialization
    // ! if int& ref - error: declaration of reference variable 'ref' requires an initializer
    // ! however you can do this in class member variable, see `binary search tree` implementation code
    // notice how 0xA is not really used anywhere

    // accessing pointer's value
    cout << "pointer's value: " << ptr << endl;
    // accessing the value at the address where pointer is pointing to
    cout << "pointer's dereferenced value: " << *ptr << endl;
    // accessing reference value, it really is the same as var
    cout << "reference value: " << ref << endl;

    std::cin.get();
}
