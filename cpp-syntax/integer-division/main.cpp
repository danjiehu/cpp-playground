#include <iostream>

int main()
{
    int a = 0;
    int b = 5;
    int res1 = (a + b) / 2;

    double c = 0.0;
    double d = 5.0;
    double res2 = (c + d) / 2;
    int res3 = (c + d) / 2;

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    std::cout << res3 << std::endl;

    return 0;
}