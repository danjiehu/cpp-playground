/*
    this demo contains:
    1. how to create std::vector & basic use of .push_back() and .size()
    2. how to print all vector content and those of custmized types

    basic usage: std::vector<int> v = { 7, 5, 16, 8 };
*/

#include <iostream>
// #include <typeinfo>
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
    // TODO: I don't understand why friend is needed here but not when overloading ==, but if removed `friend` keyword we'll get many errors
    friend std::ostream& operator<<(std::ostream& stream, const Cube& other)
    {
        stream << other.length_;
        return stream;
    }

    // overloading == to compare Cubes by length
    bool operator==(const Cube& other)
    {
        return (length_ == other.length_);
    }
};

// overloading cout to output cube_stack as std::vector type
std::ostream& operator<<(std::ostream& stream, const std::vector<Cube>& other)
{
    for (int i = 0; i < other.size(); i++) {
        stream << other[i] << " ";
    }
    return stream;
}

int main()
{
    // 1. simple int vector
    // ref: https://www.geeksforgeeks.org/vector-in-cpp-stl/
    // ref: https://en.cppreference.com/w/cpp/container/vector
    std::vector<int> v_int = { 7, 5, 16, 8 };
    v_int.push_back(25);
    v_int.push_back(13);
    cout << v_int.front() << endl;
    cout << "v_int = { ";
    for (int n : v_int) {
        cout << n << " ";
    } // range based for loop https://en.cppreference.com/w/cpp/language/range-for
    cout << "}; \n";

    // 2. below - vector of cubes
    std::vector<Cube>
        cube_stack;
    Cube c1(1);
    Cube c2(2);
    Cube c3(3);
    cout << "cube_stack vector capacity: " << cube_stack.capacity() << endl;
    cube_stack.push_back(c1);
    cout << "cube_stack vector capacity: " << cube_stack.capacity() << endl;
    cube_stack.push_back(c2);
    cout << "cube_stack vector capacity: " << cube_stack.capacity() << endl;
    cube_stack.push_back(c3);
    cout << "cube_stack vector size: " << cube_stack.size() << endl;
    cout << "cube_stack vector capacity: " << cube_stack.capacity() << endl; // notice that the capacity doubled from 2 to 4 here, larger than the size
    cout << cube_stack[0] << endl;
    cout << cube_stack[1] << endl;
    cout << cube_stack[2] << endl;
    cout << "last vector content: " << cube_stack.back() << endl;
    cout << "last vector content: " << *(cube_stack.end() - 1) << endl; // alternatively (.end() returns iterator, not really a pointer)
    cout << "first vector content: " << cube_stack.front() << endl;
    cout << "first vector content: " << *cube_stack.begin() << endl; // alternatively

    // below - finding which index c2(2) is at example code
    for (int i = 0; i < cube_stack.size(); i++) {
        if (c2 == cube_stack[i]) {
            cout << "target is at index: " << i << endl;
        }
    }

    // below - printing cube stack exmaple
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