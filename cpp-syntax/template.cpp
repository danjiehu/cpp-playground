#include <iostream>
#include <string>

//! start of exmaple one
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

template <typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    Print(5);
    Print("Hello");
    Print(5.5f);

    std::cin.get();
}
