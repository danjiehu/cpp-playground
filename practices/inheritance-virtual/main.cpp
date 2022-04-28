// virtual is used on accessing derived class member functions via a base class pointer, if the base function def has `virtual` keyword, it ensures that it will call the Dervied class same-name function instead, unless there isn't a same name function in derived class

#include <iostream>

class Base {
public:
    Base(int var)
        : var(var) {};

    virtual void print()
    {
        std::cout << "I am Base. " << std::endl;
    }
    void printVar()
    {
        std::cout << var << std::endl;
    }

private:
    int var;
};

class Derived : public Base {
public:
    Derived(int var)
        : Base(var)
        , dVar(var) {};

    void print()
    {
        std::cout << "I am Derived. " << std::endl;
    }
    // void printVar()
    // {
    //     std::cout << var << std::endl;
    // }
    void printdVar()
    {
        std::cout << dVar << std::endl;
    }

private:
    int dVar;
};

int main()
{
    Base* bptr;
    Derived d(10);

    bptr = &d;

    bptr->print();
    // without virtual, this prints "I am Base"
    // with virutal, this prints "I am Derived. " (unless we comment out derived class print() function)
    bptr->printVar();

    // this example below works with or without virtual, it does NOT make any difference
    Base base(30);
    Derived derived(40);
    base.print(); // expect: I am base.
    base.printVar(); // expect: 30.
    derived.print(); // expect: I am dervied.
    derived.printVar(); // expect: 40;
    derived.printdVar(); // expect: 40;

    return 0;
}