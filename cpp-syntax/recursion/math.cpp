
#include <iostream>

using namespace std;

int mul(int n, int m)
{
    if (n == 1)
    {
        int res = m;
        cout << n << "*" << m << " is: " << res << endl;
        return m;
    }
    else
    {
        int res = mul(n - 1, m) + m;
        cout << n << "*" << m << " is: " << res << endl;
        return res;
    }
};

int fac(int n)
{
    if (n == 1)
    {
        int res = 1;
        cout << "factorial " << n << " is: " << res << endl;
        return res;
    }
    else
    {
        int res = n * fac(n - 1);
        cout << "factorial " << n << " is: " << res << endl;
        return res;
    }
}

int main()
{
    // multiplication
    mul(1, 2);

    // n factorial
    fac(5);
}