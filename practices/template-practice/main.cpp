#include <iostream>

// ex-1: template as function argument
template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

// ex-2: template as class member variable

int main()
{
    // ex-1:
    std::cout << max(10, 20) << std::endl; // variable is defined when the function is called automatically
    std::cout << max<double>(10.4, 20.12) << std::endl; // variable is defined when the function is called with an signed type

    return 0;
}