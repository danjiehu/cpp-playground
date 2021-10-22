
#include <iostream>

using namespace std;

int mul(int n, int m)
{
    if (n == 1)
    {
        cout << m << endl;
        return m;
    }
    else
    {
        int res = mul(n - 1, m) + m;
        cout << res << endl;
        return res;
    }
};

int main()
{
    // > multiplication
    mul(1, 2);
    // < multiplication

    // > n factorial

    // < n factorial
}