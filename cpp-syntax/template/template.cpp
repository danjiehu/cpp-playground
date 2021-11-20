//!template is "how to create code" specified for the compiler, compiler can then automatically create code for you basing on your usage of them
#include <iostream>
#include <string>

// void Print(int value)
// {
//     std::cout << value << std::endl;
// }

// void Print(std::string value)
// {
//     std::cout << value << std::endl;
// }

// void Print(float value)
// {
//     std::cout << value << std::endl;
// }

//!templates are evaluated at compile time, unlike regular code that is evaluated at runtime
//!use templates when you want the compiler to write code for you based on your rules (warning: overusing template will make your code harder to read for you and others)
template <typename T> // T is called "template parameter"
void Print(T value)
{
    std::cout << value << std::endl;
};

template <int N>
class Array {
private:
    int m_Array[N];

public:
    int GetSize() const { return N; }
};
//when Array<5> array; is called, a class below gets created by the compiler
// class Array {
// private:
//     int m_Array[5];

// public:
//     int GetSize() const { return 5; }
// }

template <typename T, int N>
class ArrayT {
private:
    T m_Array[N];

public:
    int GetSize() const { return N; }
};

int main()
{
    //! start of exmaple one: print different types
    Print(5);
    Print<int>(6); // int is the template argument
    Print("Hello");
    Print(5.5f);
    std::cin.get();

    //! start of example two: creating stack arrays by creating customized class
    Array<5> array; // 5 is the template argument
    std::cout << array.GetSize() << std::endl;

    ArrayT<std::string, 50> array2;
    std::cout << array2.GetSize() << std::endl;
    std::cin.get();

    return 0;
}
