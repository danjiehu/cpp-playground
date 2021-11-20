/*
in deep copy, 
we need to explicitly define a custom constructor & assignment operator
then when copy/assign, 
all variables incl. heap will be allocated new storage address
*/

#include <iostream>
using namespace std;

class box
{
private:
    int length;
    int breadth;
    int *height;

public:
    // custom default constructor
    // once you defined a copy constructor, you must define a build constructor
    // other wise get error below
    /*
    error: no matching constructor for initialization of 'box'
    candidate constructor not viable: requires single argument 'obj', 
        but no arguments were provided
    */

    box()
    {
        length = 1;
        breadth = 1;
        height = new int;
        *height = 1;
        /*
            or simple write this line:
            height = new int;
        */
    }

    // custom copy constructor
    box(const box &obj)
    {
        length = obj.length;
        breadth = obj.breadth;
        height = new int;
        *height = *(obj.height);
        // the height variable is a pointer, therefore must be deferenced on both sides
        // you need to define len, bread & heig too!!
    }

    //custom assignment operator
    box &operator=(const box &obj)
    {
        length = obj.length;
        breadth = obj.breadth;
        height = new int;
        *height = *(obj.height);
        return *this;
    }

    void set_dimensions(int len, int brea, int heig)
    {
        length = len;
        breadth = brea;
        *height = heig;
    }

    void show_data()
    {
        cout << "length is " << length << ", address is " << &length
             << "\n breadth is " << breadth << ", address is " << &breadth
             << "\n height is " << *height << ", address is " << height << endl;
    }
};

int main()
{
    box b1;

    b1.set_dimensions(1, 2, 3);
    b1.show_data();
    cout << "end of b1: the original box" << endl;

    //custom copy constructor to perform deep copy;
    box b2 = b1;
    b2.show_data();
    cout << "end of b2: copies b1" << endl;

    //custom assigment operator to perform deep copy;
    box b3;
    b3 = b1;
    b3.show_data();
    cout << "end of b3: assigned b1" << endl;

    return 0;
}
