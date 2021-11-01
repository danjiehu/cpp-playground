/*
    this demo contains: 
    1. 
*/
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Cube {
private:
    int length_;

public:
    Cube(int leng)
        : length_(leng)
    {
    }

    // this function can be public or private, doesn't matter
    // it allows cout to reference private member length_ outside of the class
    friend std::ostream& operator<<(std::ostream& stream, const Cube& other)
    {
        stream << other.length_ << endl;
        return stream;
    }
};

int main()
{
    // below - vector of cubes
    std::vector<Cube> stack;
    Cube c1(4);
    stack.push_back(c1);
    cout << stack[0] << endl;

    // below - simplest vector int example
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    return 0;
}