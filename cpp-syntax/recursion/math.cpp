
#include <iostream>

using namespace std;

// multiplication
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

// n factorial
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

    mul(3, 4);
    fac(5);
}