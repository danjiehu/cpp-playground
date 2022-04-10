/*
in shallow copy, we use default constructor and default assignment operator,
- stack class member variable of the copiee object will use a new memory address
- heap class member variable of the copiee object will use the SAME memory address of the copier object
! that's why some times we need to write our own copy constructor and assignment operator
*/

#include <iostream>
using namespace std;

class box {
private:
    int length;
    int breadth;
    int* height;

public:
    void set_dimensions(int len, int brea, int heig)
    {
        length = len;
        breadth = brea;

        height = new int;
        *height = heig;
    }

    void show_data()
    {
        cout << "length is " << length << ", address is " << &length
             << "\n breadth is " << breadth << ", address is " << &breadth
             << "\n height is " << *height << ", address is " << height << endl;
    }

    // ~box()
    // {
    //     delete height;
    // }
    // this program has memory leak
};

int main()
{
    box b1;

    b1.set_dimensions(1, 2, 3);
    b1.show_data();
    cout << "end of b1: original" << endl;

    // automatic copy constructor;
    box b2 = b1;
    b2.show_data();
    // ! you'll see that address of b2.height is the same address of b1.height
    cout << "end of b2: copies b1" << endl;

    // automatic assigment operator;
    box b3;
    b3 = b1;
    b3.show_data();
    // ! you'll see that address of b3.height is the same address of b1.height
    cout << "end of b3: assigned b1" << endl;

    return 0;
}
