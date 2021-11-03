/*
    this demo contains: 
    1. how to create std::vector & basic use of .push_back() and .size()
    2. how to print all vector content and those of custmized types
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
        stream << other.length_;
        return stream;
    }
};

std::ostream& operator<<(std::ostream& stream, const std::vector<Cube>& other)
{
    for (int i = 0; i < other.size(); i++) {
        stream << other[i] << " ";
    }
    return stream;
}

int main()
{
    // below - vector of cubes
    std::vector<Cube> cube_stack;
    Cube c1(1);
    Cube c2(2);
    Cube c3(3);
    cube_stack.push_back(c1);
    cube_stack.push_back(c2);
    cube_stack.push_back(c3);
    cout << cube_stack[0] << endl;
    cout << cube_stack[1] << endl;
    cout << cube_stack[2] << endl;

    //below - printing cube stack exmaple
    cout << "cube stack is: " << cube_stack << endl;

    // below - simple vector int example
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    return 0;
}