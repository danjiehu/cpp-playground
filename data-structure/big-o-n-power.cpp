// this cpp file documents some examples programs that has the big o of n^x

// some math prounciation examples
// 2^16 is read "two to the sixteenth", "two to the sixteen", "two raised to the sixteenth power" or "two to the power of sixteen"
// n^2  is read n squared, n^3 is read n cubed
// ∜5 is read "4th root of five", x√2 is read x-th root of two
// log2(8) is read log 2 of 8

#include <iostream>

void n_squared(int n)
{
    int n_squared;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            n_squared++;
            std::cout << i << ", " << j << std::endl;
            std::cout << n_squared << std::endl;
        }
    }
}

int main()
{
    n_squared(8); // this is a o(n^2) function

    std::cin.get();
}