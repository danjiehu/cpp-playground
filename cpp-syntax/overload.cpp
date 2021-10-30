/*
this example contains
1. operator overload: +, *, ostream, ref https://www.youtube.com/watch?v=mS9755gF66w&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=41&t=250s
2. struct vs. class type, ref http://c.biancheng.net/view/2235.html
struct vector

*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;

struct vector {
    float x, y;

    vector(float x, float y)
        : x(x)
        , y(y)
    {
    }
};

int main()
{
    vector position(4.0f, 4.0f);
    vector speed(0.5f, 1.5f);

    return 0;
}

/* start of - demo: how you would write without operator overload 
struct vector {
    float m_x, m_y;

    vector(float x, float y)
        : m_x(x)
        , m_y(y)
    {
    }

    vector add(const vector& other) const
    {
        return vector(m_x + other.m_x, m_y + other.m_y);
    }

    vector multiply(const vector& other) const
    {
        return vector(m_x * other.m_x, m_y * other.m_y);
    }
};

int main()
{
    vector position(4.0f, 4.0f);
    vector speed(0.5f, 1.5f);
    vector powerup(1.1f, 1.1f);

    vector result = position.add(speed.multiply(powerup));
    cout << "result.m_x: " << result.m_x << endl;
    cout << "result.m_y: " << result.m_y << endl;

    return 0;
}

end of - demo: how you would write without operator overload */
