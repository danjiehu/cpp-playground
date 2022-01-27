// demo contains
// 1. examples of copy constructor
// 2. examples of assignment operator
// in general, copy constructor is called when the object doesn't exist before (therefore needs to be constructed)
// assignment operator is called when the object already exist/constructed, but we are changing its attributes by copying from another same-type object
// once an object is created, it can never be constructed again; that's why we're replacing the values with assignment operator. the automatic assignment operator will suffice in most case.

#include <iostream>

class Cube {
public:
    Cube(); // custom default constructor;
    Cube(double leng); // custom constructor with user input;

    Cube(const Cube& obj); // custom copy constructor
    // ! must remeber if function is prepared to be defined later, don't add {} yet!!

    Cube& operator=(const Cube& obj);
    // custom assignment operator a public function of the class that has a return type of Cube&

    double getVolume();
    void setLength(double length);

private:
    double length_;
};

// custom default constructor
Cube::Cube()
{
    length_ = 1;
    std::cout << "default constructor invoked! " << std::endl;
};

// custom constructor with user input with initializer list
Cube::Cube(double leng)
    : length_(leng)
{
    std::cout << "custom constructor with parameter invoked! " << std::endl;
};

// custom copy constructor
// 1. exactly one argument passed by const reference
// 2. define what attributes and how you want the current object to copy from the argument obejct that is passed in
// 3. view in main the invocation of copy constructor
Cube::Cube(const Cube& obj)
{
    length_ = obj.length_;
    std::cout << "copy constructor invoked!" << std::endl;
};

// customer assignment operator
Cube& Cube::operator=(const Cube& obj)
{
    length_ = obj.length_;
    std::cout << "assignment operator invoked!" << std::endl;
    return *this; // ! copy assignment operator has a return type, remeber to `return *this;`
    // `this` is pointing to the instance of the class itself, so return `*this` is simply returning the current instance of the class
}

// a class member function
double Cube::getVolume()
{
    return length_ * length_ * length_;
}

// copy construcotr invocaiton-1: function argument pased in by value
void foo1(Cube c)
{
    std::cout << "executing function foo1; " << std::endl;
};

// copy constructor invocation-2: returning an object from function by value
Cube foo2()
{
    std::cout << "executing function foo2; " << std::endl;
    Cube c; // invoke default constructor
    return c; // invoke copy constructor, copying c to main frame stack
}

int main()
{
    Cube c;

    // copy construcotr invocaiton-1: function argument pased in by value
    foo1(c);

    // copy constructor invocation-2: returning an object from function by value
    // Cube copiedCube = foo2();
    // invoke copy constructor again when copiedCube takes one the values of what's been returned from function
    // ! this does not work in the current setting of my compiler, but you can see cpp-cctor/ex2 with make compile to check how the copy constructor is invoked 2 times
    // TODO: ask in forum if my assumption about why it doesn't work in my current setting may be valid - compiler optimization

    // copy constructor invocation-3: constructing a new object that takes on the value of an existing object;
    Cube anotherCopiedCube = c;

    // assignment operator invocation
    Cube c1; // length_ is one, constructed
    Cube c2(2); // length is two, constructed
    c1 = c2; // now c1 has the length of two via the assignment operator

    return 0;
}