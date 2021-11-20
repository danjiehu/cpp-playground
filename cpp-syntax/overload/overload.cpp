/*
this demo contains
1. operator overload: +, *, <<, ==, !=, ref https://www.youtube.com/watch?v=mS9755gF66w&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=41&t=250s
2. struct vs. class type, ref http://c.biancheng.net/view/2235.html
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;

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
    //!operator + overload
    vector operator+(const vector& other) const { return add(other); }

    vector multiply(const vector& other) const
    {
        return vector(m_x * other.m_x, m_y * other.m_y);
    }
    //!operator * overload
    vector operator*(const vector& other) const { return multiply(other); }

    //!operator == overload
    bool operator==(const vector& other) const
    {
        return m_x == other.m_x && m_y == other.m_y;
    }

    //!operator != overload
    bool operator!=(const vector& other) const
    {
        return !(*this == other);
    }
};

//! cout << overload
//this is or overload cout, which has nothing to do with the struct vector, therefore it's outside of the struct
//it doesn't have `const` before {} because this function is not inside of any class/struct
std::ostream& operator<<(std::ostream& stream, const vector& other)
{
    stream << other.m_x << "," << other.m_y;
    return stream;
}

int main()
{
    vector position(4.0f, 4.0f);
    vector speed(0.5f, 1.5f);
    vector powerup(1.1f, 1.1f);

    vector result = position + speed * powerup;
    cout << result << endl; // this works because of << overload

    if (position == speed) {
        cout << "position vector equals speed vector" << endl;
    } else {
        cout << "position vector doesn't equals speed vector" << endl;
    }

    return 0;
}

/* start of - how you would write without operator overload 
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
end of - how you would write without operator overload */
