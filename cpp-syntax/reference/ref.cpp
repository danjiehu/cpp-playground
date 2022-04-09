// a reference means, the variable is going to take on the address that assigned to it
// int& a = b; // a is going to take on the address of b, and you can now refer to the address as `a` too.
// ! syntax: accessing the value stored at the reference variable address does NOT need to dereference it
// for example,
// int b = 10;
// int& a = b; // this is the equivalent of int* a = &b;
// std::cout << a << std::endl; //10 //accessing stored value is *b (dereferenced b)

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int b = 10;
    int& a = b; // this is the equivalent of int* a = &b;
    std::cout << "value of reference a: " << a << std::endl; // 10 //accessing stored value is *b (dereferenced b)
    std::cout << "value of address of b: " << &b << std::endl;
    std::cout << "value of address of a: " << &a << std::endl;

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

    // 2. mimicing pass by const reference
    // ! all examples in 2 and 3, data and dataArgument have different address
    // example 2.1
    int data; // mimicing class member variable
    const int& dataArgument = 8;
    // dataArgument = 9; error: variable 'dataArgument' declared const here
    data = dataArgument;
    cout << data << endl; // 8
    cout << dataArgument << endl; //  8
    cout << &data << endl; // 0xA
    cout << &dataArgument << endl; // ! 0xB, two different address

    // example 2.2 pass by const reference gives you the flexibility to pass in an argument with an existing variable, and it doesn't create a copy of that variable
    int data_2;
    int x = 9;
    const int& dataArgument_2 = x;
    // dataArgument_2 = 10; // error: cannot assign to variable 'dataArgument_2' with const-qualified type 'const int &'
    x = 10; // but you can do this, which is weird but it is what it is
    data_2 = dataArgument_2;
    cout << x << endl; // 10
    cout << &x << endl; // 0xA
    cout << data_2 << endl; // 10
    cout << &data_2 << endl; // output 0xB
    cout << dataArgument_2 << endl; // output 10
    cout << &dataArgument_2 << endl; // ! output 0xA, x and dataArgument are same address, different address with data_2

    // 3. mimicing pass by value
    // example 3.1
    int m_data;
    const int dataArgu = 100;
    m_data = dataArgu;
    cout << m_data << "\n" // 100
         << &m_data << endl; // 0xA
    cout << dataArgu << "\n" // 100
         << &dataArgu << endl; // ! 0xB, two different address, exactly the same as exmaple 2.1

    // example 3.2
    int m_data2;
    int y = 101;
    const int dataArgu_2 = y;
    m_data2 = dataArgu_2;
    cout << y << "\n" // 101
         << &y << "\n" // 0xA
         << dataArgu_2 << "\n" // 101
         << &dataArgu_2 << "\n" // ! 0xB, different from example 2.2, y and data_argument are two DIFFERENT variables
         << m_data2 << "\n" // 101
         << &m_data2 // 0xC
         << endl;

    // 4. mimicing declaring class member as reference, see real implementaion at binary search tree demo
    // !!! examples in 4, data and dataArgument have the SAME address - that's difference with declaring class member as reference type
    const int& dataArg = 200;
    const int& mData = dataArg;
    // if mData a reference, it has to be the same reference type as dataArg
    // for example, if `int& mData = datArg; `, error: binding reference of type 'int' to value of type 'const int' drops 'const' qualifier
    cout << dataArg << "\n" // 200
         << &dataArg << "\n" // 0xA
         << mData << "\n" // 200
         << &mData << endl; // !!! 0xA, now the member data and data argument passed in via constructor have the same address

    std::cin.get();
}
