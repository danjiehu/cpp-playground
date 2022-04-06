// this cpp file documents some examples programs that has the big o of n^x

// -o(1) is called constant time
// -o(n) is called linear time
// -o(n^2) is called polynomial time

// some math prounciation examples
// 2^16 is read "two to the sixteenth", "two to the sixteen", "two raised to the sixteenth power" or "two to the power of sixteen"
// n^2  is read n squared, n^3 is read n cubed
// ∜5 is read "4th root of five", x√2 is read x-th root of two
// log2(8) is read log 2 of 8

#include <iostream>

void n_squared(int n)
{
    int n_squared = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            n_squared++;
            std::cout << i << ", " << j << std::endl;
            std::cout << n_squared << std::endl;
        }
    }
}

void n_cubed(int n)
{
    int n_cubed = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                n_cubed++;
                std::cout << i << ", " << j << ", " << k << std::endl;
                std::cout << n_cubed << std::endl;
            }
        }
    }
}

void combined(int n)
{
    n_squared(n);
    n_cubed(n);
}

int main()

{
    // define the number of steps it takes to resolve the function as `steps`
    // define the input number as `n`
    // summarize the abstract math relation between the two as `steps = o(n?)`

    n_squared(2);
    // steps = 2^2 = n^2 = 4, \lim_{n \to ∞} n^2 = n^2 - therefore, n_squared(n) is a o(n^2) algo
    n_cubed(2);
    // steps = 2^3 = n^3 = 8, \lim_{n \to ∞} n^3 = n^3 - therefore, n_cubed(n) is a o(n^3) algo

    combined(3);
    // steps = 3^2 + 3^3 = n^2 + n^3 = 36
    // ! when we evaluate algo efficiency, we are evaulating when n reaches ∞ (infinity)
    // so what we wanna work out is a polynomial limit: \lim_{n \to ∞} n^2 + n^3
    // because the growth rate n^3 is larger than n^2, \lim_{n \to ∞} n^2 + n^3 = n^3
    // therefore, combined(n) is a o(n^3) algo

    // ref: find the limite at infinity https://www.youtube.com/watch?v=nViVR1rImUE
    // ref: representing the imit (mathematics) sign? https://tex.stackexchange.com/questions/74969/how-to-make-the-limit-mathematics-sign

    std::cin.get();
}