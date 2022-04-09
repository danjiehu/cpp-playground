#include <iostream>

class Pair {
public:
    double a, b;
};

int main()
{
    Pair* p = new Pair;
    (*p).a = 22.0;
    p->b = 23.2;

    // assessing heap class member variable syntax
    std::cout << p->a << std::endl;
    std::cout << p->b << std::endl;

    Pair stack_p;
    stack_p.a = 32;
    stack_p.b = 33;

    // accessing stack class member variable syntax
    std::cout << stack_p.a << std::endl;
    std::cout << stack_p.b << std::endl;

    return 0;
}