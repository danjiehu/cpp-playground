#include <iostream>
#include <string>
using namespace std;

class box
{
private:
    int length;
    int breadth;
    int *height;

public:
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

    //default copy constructor;
    box b2 = b1;
    b2.show_data();

    //assigment operator;
    box b3;
    b3 = b1;
    b3.show_data();

    return 0;
}